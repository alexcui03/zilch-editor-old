#include "SpriteItem.h"

SpriteItem::SpriteItem(ScratchSprite *Sprite, QWidget *parent) : Widget(parent) {
	this->Sprite = Sprite;
	this->setObjectName("SpriteItem");
}
