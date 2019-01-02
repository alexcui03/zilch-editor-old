#include "ScratchStage.h"

ScratchStage::ScratchStage() : ScratchObject("Stage") {

}

void ScratchStage::CreateNew() {
	this->Sprite.push_back(ScratchSprite("Sprite"));
}
