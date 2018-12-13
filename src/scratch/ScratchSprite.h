#ifndef SCRATCHSPRITE_H
#define SCRATCHSPRITE_H

#include <string>

enum class SpriteRotationStyle { FREE, LINE, NONE };

class ScratchSprite {
public:
	ScratchSprite(std::string Name);
public:
	std::string Name;
	SpriteRotationStyle RotationStyle;
	bool Draggable;
	bool Show;
	int Direction;
};

#endif // SCRATCHSPRITE_H
