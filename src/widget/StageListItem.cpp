#include "StageListItem.h"
#include "SpriteListItem.h"

StageListItem::StageListItem(ScratchStage *stage, QWidget *parent) : ObjectListItem(stage, parent) {
	this->resize(75, 75);

	this->text->move(0, 57);
	this->text->resize(75, 15);
}

StageListItem::~StageListItem() {

}
