#include "EditArea.h"
#include "../translator/Translator.h"
#include "../scratch/Scratch.h"
#include <QTabBar>

/**
 * @brief EditArea::EditArea - Constructor.
 * @param {QWidget*} parent - Parent widget.
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

	TabWidget->addTab(ScriptPart, "Script");
	TabWidget->addTab(CostumePart, "Costume");
}

/**
 * @brief EditArea::resizeEvent - Resize event.
 * @param {QResizeEvent*} - Resize event.
 */
void EditArea::resizeEvent(QResizeEvent *) {
	TabWidget->resize(this->width(), this->height());
}

/**
 * @brief EditArea::ChangeObject
 * @param {ScratchObject*} Object - Sprite or stage.
 */
void EditArea::ChangeObject(ScratchObject *Object) {
	this->Object = Object;
	this->ScriptPart->ScriptEdit->Reload();
}


