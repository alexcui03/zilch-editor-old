#include "ScratchBlock.h"

ScratchBlock::ScratchBlock(ScratchBlockPrototype *Block, ScratchBlock *LastBlock, ScratchBlock *NextBlock) {
	this->Block = Block;
	this->LastBlock = LastBlock;
	this->NextBlock = NextBlock;
	this->X = this->Y = 0;
}

bool ScratchBlock::isHead() {
	return this->LastBlock == nullptr;
}
