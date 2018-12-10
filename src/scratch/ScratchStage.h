#ifndef SCRATCHSTAGE_H
#define SCRATCHSTAGE_H

#include <list>
#include "ScratchSprite.h"

class ScratchStage {
public:
	ScratchStage();
public:
	std::list<ScratchSprite> Sprite;
};

#endif // SCRATCHSTAGE_H
