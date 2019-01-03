#ifndef SCRATCHSTAGE_H
#define SCRATCHSTAGE_H

#include <vector>
#include "ScratchObject.h"
#include "ScratchSprite.h"

class ScratchStage : public ScratchObject {
public:
	ScratchStage();
	void CreateNewSprite();
public:
	std::vector<ScratchSprite> Sprite;
};

#endif // SCRATCHSTAGE_H
