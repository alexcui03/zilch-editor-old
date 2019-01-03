#include "SpriteItem.h"
#include <QImage>
#include <QPixmap>

SpriteItem::SpriteItem(ScratchSprite *Sprite, QWidget *parent) : Widget(parent) {
	this->Sprite = Sprite;
	this->setObjectName("SpriteItem");

	this->Label = new QLabel(this);
	this->Label->move(0, 0);
	this->Label->setPixmap(QPixmap::fromImage(*static_cast<QImage*>(this->Sprite->CostumeList[this->Sprite->CurrentCostume].Resourse->Data)));
}
