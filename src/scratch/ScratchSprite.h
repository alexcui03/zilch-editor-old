#ifndef SCRATCHSPRITE_H
#define SCRATCHSPRITE_H

#include <string>
#include "ScratchObject.h"

enum class SpriteRotationStyle { FREE, LINE, NONE };

class ScratchSprite : public ScratchObject {
public:
	ScratchSprite(std::string Name);
public:
	SpriteRotationStyle RotationStyle;
	bool Draggable;
	bool Show;
	int Direction;
};

#endif // SCRATCHSPRITE_H
