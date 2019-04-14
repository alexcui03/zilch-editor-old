#include "StageItem.h"
#include "MainWindow.h"

StageItem::StageItem(ScratchStage *stage, QWidget *parent) : ObjectItem(stage, parent) {
	this->label = nullptr;
}

StageItem::~StageItem() {

}
