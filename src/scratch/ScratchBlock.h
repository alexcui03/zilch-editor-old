#ifndef SCRATCHBLOCK_H
#define SCRATCHBLOCK_H

#include <string>

class ScratchBlockCategory;

enum class ScratchBlockType {
	HEAD_BLOCK,
	BODY_BLOCK,
	TAIL_BLOCK,
	BOOL_BLOCK,
	NUMB_BLOCK,
	NULL_BLOCK
};

class ScratchBlock {
public:
	ScratchBlock(ScratchBlockCategory *Category, std::string Name, ScratchBlockType Type);
public:
	ScratchBlockCategory *Category;
	ScratchBlockType Type;
	std::string Name;
};

#endif // SCRATCHBLOCK_H
