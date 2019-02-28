#ifndef SCRATCHBLOCK_H
#define SCRATCHBLOCK_H

#include "ScratchBlockPrototype.h"

class ScratchObject;
class BlockItem;

class ScratchBlock {
public:
	ScratchBlock(ScratchBlockPrototype *Block, ScratchObject *Object, ScratchBlock *LastBlock = nullptr, ScratchBlock *NextBlock = nullptr);
	~ScratchBlock();
	bool isHead();
	void Run(ScratchObject *Object);
public:
	ScratchObject *Object;
	ScratchBlockPrototype *Block;
	ScratchBlock *LastBlock;
	ScratchBlock *NextBlock;
	BlockItem *Item;
	int X;
	int Y;
};

#endif // SCRATCHBLOCK_H
