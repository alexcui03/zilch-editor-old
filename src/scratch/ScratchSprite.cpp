#include "ScratchSprite.h"
#include "ScratchStage.h"
#include "Scratch.h"
#include "../widget/SpriteItem.h"

ScratchStage *ScratchSprite::Stage = &ScratchMain.Stage;

/**
 * @brief ScratchSprite::ScratchSprite - Constructor.
 * @param {std::string} Name - Sprite name.
 */
ScratchSprite::ScratchSprite(std::string Name) : ScratchObject(Name) {
	this->RotationStyle = SpriteRotationStyle::FREE;
	this->Draggable = false;
	this->Show = true;
	this->Direction = 90;
}

void ScratchSprite::move(int x, int y) {
	this->Item->move(x, y);
}

int ScratchSprite::getx() {
	return this->Item->x();
}
int ScratchSprite::gety() {
	return this->Item->y();
}
