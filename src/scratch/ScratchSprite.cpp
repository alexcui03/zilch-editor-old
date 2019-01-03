#include "ScratchSprite.h"
#include "ScratchStage.h"
#include "Scratch.h"

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
	this->Item = nullptr;
}
