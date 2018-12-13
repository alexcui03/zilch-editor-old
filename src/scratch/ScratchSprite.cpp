#include "ScratchSprite.h"

/**
 * @brief ScratchSprite::ScratchSprite - Constructor.
 * @param {std::string} Name - Sprite name.
 */
ScratchSprite::ScratchSprite(std::string Name) {
	this->Name = Name;
	this->RotationStyle = SpriteRotationStyle::FREE;
	this->Draggable = false;
	this->Show = true;
	this->Direction = 90;
}
