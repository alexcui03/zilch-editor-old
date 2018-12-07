#include "ScratchBlock.h"
#include "ScratchBlockCategory.h"

ScratchBlock::ScratchBlock(ScratchBlockCategory *Category, std::string Name, ScratchBlockType Type) {
	this->Name = Name;
	this->Category = Category;
	this->Type = Type;

	Category->Block.push_back(this);
}
