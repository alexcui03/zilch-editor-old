#include "EditArea.h"
#include "../translator/Translator.h"
#include <QTabBar>

EditArea::EditArea(QWidget *parent):Widget(parent) {
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

void EditArea::resizeEvent(QResizeEvent *) {
	TabWidget->resize(this->width(), this->height());
}
