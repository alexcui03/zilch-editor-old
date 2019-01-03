#include "ScratchStage.h"
#include <cstdio>

ScratchStage::ScratchStage() : ScratchObject("Stage") {

}

void ScratchStage::CreateNewSprite() {
	static int SpriteID = 0;
	char Name[64];
	sprintf(Name, "Sprite %d", SpriteID++);
	this->Sprite.push_back(ScratchSprite(Name));
}
