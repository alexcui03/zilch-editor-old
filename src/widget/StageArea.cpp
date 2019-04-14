#include "StageArea.h"

#include "StageView.h"
#include "../scratch/Scratch.h"

StageArea::StageArea(QWidget *parent):Widget(parent) {
	StageView = new ::StageView(this);
	StageView->Widget::setObjectName("StageArea_StageView");
	StageView->Widget::move(0, 35);
	StageView->Widget::resize(480, 360);

	StageItem = new ::StageItem(&ScratchMain.Stage, this);
	StageItem->label = StageView;
	ScratchMain.Stage.Item = StageItem;

	ButtonStart = new QPushButton(this);
	ButtonStart->setObjectName("StageArea_ButtonStart");
	ButtonStart->move(415, 7);
	ButtonStart->resize(21, 21);

	ButtonStop = new QPushButton(this);
	ButtonStop->setObjectName("StageArea_ButtonStop");
	ButtonStop->move(445, 7);
	ButtonStop->resize(21, 21);

	connect(ButtonStart, SIGNAL(clicked()), this, SLOT(RunProgram()));
}

StageArea::~StageArea() {

}

void StageArea::reloadTranslation() {
	this->StageView->reloadTranslation();
	// > Before 0.3.0.656:
	// >   class StageView : Widget
	// > After:
	// >   class StageView : QLabel
}

void StageArea::RunProgram() {
	ScratchMain.ProgramRun();
}

