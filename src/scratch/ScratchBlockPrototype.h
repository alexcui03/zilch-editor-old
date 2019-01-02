#ifndef SCRATCHBLOCKPROTOTYPE_H
#define SCRATCHBLOCKPROTOTYPE_H

#include <string>
#include <functional>

class ScratchObject;
class ScratchBlockCategory;

typedef std::function<void(ScratchObject*)> ScratchBlockFuntion;

enum class ScratchBlockType {
	HEAD_BLOCK,
	BODY_BLOCK,
	TAIL_BLOCK,
	BOOL_BLOCK,
	NUMB_BLOCK,
	NULL_BLOCK
};

class ScratchBlockPrototype {
public:
	ScratchBlockPrototype(ScratchBlockCategory *Category, std::string Name, ScratchBlockType Type, ScratchBlockFuntion Function);
	~ScratchBlockPrototype();
public:
	ScratchBlockCategory *Category;
	ScratchBlockType Type;
	std::string Name;
	ScratchBlockFuntion Function;
};

#endif // SCRATCHBLOCK_H
