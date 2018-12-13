#ifndef SCRATCHSTAGE_H
#define SCRATCHSTAGE_H

#include <vector>
#include "ScratchSprite.h"

class ScratchStage {
public:
	ScratchStage();
public:
	std::vector<ScratchSprite*> Sprite;
};

#endif // SCRATCHSTAGE_H
