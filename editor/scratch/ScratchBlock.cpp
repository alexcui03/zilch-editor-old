#include "ScratchBlock.h"
#include "../widget/BlockItem.h"

ScratchBlock::ScratchBlock(ScratchBlockPrototype *Block, ScratchBlock *LastBlock, ScratchBlock *NextBlock) {
	this->Block = Block;
	this->LastBlock = LastBlock;
	this->NextBlock = NextBlock;
	this->Item = nullptr;
	this->X = this->Y = 0;
}

ScratchBlock::~ScratchBlock() {
	delete this->Item;
}

bool ScratchBlock::isHead() {
	return this->LastBlock == nullptr;
}
