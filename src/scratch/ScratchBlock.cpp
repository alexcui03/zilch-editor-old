#include "ScratchBlock.h"
#include "ScratchObject.h"
#include "../widget/BlockItem.h"
#include "../logger/Logger.h"

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

void ScratchBlock::Run(ScratchObject *Object) {
	AppLogger.AddLog("Runtime", "Run block[", Object->Name, "]: ", this->Block->Name);
	this->Block->Function(Object);
	if (this->NextBlock != nullptr) {
		this->NextBlock->Run(Object);
	}
}
