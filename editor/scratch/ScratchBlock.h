#ifndef SCRATCHBLOCK_H
#define SCRATCHBLOCK_H

#include "ScratchBlockPrototype.h"

class BlockItem;

class ScratchBlock {
public:
	ScratchBlock(ScratchBlockPrototype *Block, ScratchBlock *LastBlock = nullptr, ScratchBlock *NextBlock = nullptr);
	~ScratchBlock();
	bool isHead();
public:
	ScratchBlockPrototype *Block;
	ScratchBlock *LastBlock;
	ScratchBlock *NextBlock;
	BlockItem *Item;
	int X;
	int Y;
};

#endif // SCRATCHBLOCK_H
