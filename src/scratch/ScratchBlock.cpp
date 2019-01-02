#include "ScratchBlock.h"
#include "ScratchObject.h"
#include "../widget/BlockItem.h"

ScratchBlock::ScratchBlock(ScratchBlockPrototype *Block, ScratchBlock *LastBlock, ScratchBlock *NextBlock) {
	this->Block = Block;
	this->LastBlock = LastBlock;
	this->NextBlock = NextBlock;
	this->Item = nullptr;
	this->Object = nullptr;
	this->X = this->Y = 0;
}

ScratchBlock::~ScratchBlock() {
	delete this->Item;
}

bool ScratchBlock::isHead() {
	return this->LastBlock == nullptr;
}

void ScratchBlock::Run() {
	this->Block->Function(this->Object);
	if (this->NextBlock != nullptr) {
		this->NextBlock->Run();
	}
}
