#include "SpriteItem.h"
#include <QImage>
#include <QPixmap>
#include "../logger/Logger.h"

SpriteItem::SpriteItem(ScratchSprite *sprite, QWidget *parent) : ObjectItem(sprite, parent) {
	this->setObjectName("SpriteItem");
	this->move(240, 180);

	this->label = new QLabel(this);
	this->label->move(0, 0);
	this->label->setPixmap(QPixmap::fromImage(*static_cast<QImage*>(this->object->CostumeList[this->object->CurrentCostume].resource->Data)));
	this->label->adjustSize();

	this->adjustSize();
}

SpriteItem::~SpriteItem() {
	delete this->label;
}

void SpriteItem::reload() {
	this->label->setPixmap(QPixmap::fromImage(*static_cast<QImage*>(this->object->CostumeList[this->object->CurrentCostume].resource->Data)));
	this->label->adjustSize();

	this->adjustSize();
}

