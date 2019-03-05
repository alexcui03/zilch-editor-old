#include "EditArea.h"

#include <QTabBar>

#include "../translator/Translator.h"
#include "../scratch/Scratch.h"

/**
 * Constructor.
 * parent : The parent widget pointer.
 */
EditArea::EditArea(QWidget *parent):Widget(parent) {
	this->Object = &ScratchMain.Stage;

	TabWidget = new QTabWidget(this);
	TabWidget->setObjectName("EditArea_TabWidget");
	TabWidget->tabBar()->setObjectName("EditArea_TabWidget_TabBar");
	TabWidget->move(0, 0);
	TabWidget->resize(this->width(), this->height());

	ScriptPart = new ::ScriptPart();
	ScriptPart->setObjectName("EditArea_ScriptPart");
	CostumePart = new ::CostumePart();
	CostumePart->setObjectName("EditArea_CostumePart");

	ScriptPart->index = TabWidget->addTab(ScriptPart, AppTranslator["editarea_tab_scriptpart"]);
	CostumePart->index = TabWidget->addTab(CostumePart, AppTranslator["editarea_tab_costumepart"]);
}

EditArea::~EditArea() {
	delete this->TabWidget;
	delete this->ScriptPart;
	delete this->CostumePart;
}

void EditArea::reloadTranslation() {
	TabWidget->setTabText(ScriptPart->index, AppTranslator["editarea_tab_scriptpart"]);
	TabWidget->setTabText(CostumePart->index, AppTranslator["editarea_tab_costumepart"]);

	this->ScriptPart->reloadTranslation();
	this->CostumePart->reloadTranslation();
}

/**
 * Called when the widget size changes.
 */
void EditArea::resizeEvent(QResizeEvent *) {
	TabWidget->resize(this->width(), this->height());
}

/**
 * To call all the widgets to change data.
 * This function will be called when any ObjectListItem was clicked.
 */
void EditArea::ChangeObject(ScratchObject *Object) {
	this->Object = Object;
	this->ScriptPart->ScriptEdit->Reload();
	this->CostumePart->costume_list->reload();
}


