#include "ScratchBlockPrototype.h"
#include "ScratchBlockCategory.h"

ScratchBlockPrototype::ScratchBlockPrototype(ScratchBlockCategory *Category, std::string Name, ScratchBlockType Type, std::function<void()> Function) {
	this->Name = Name;
	this->Category = Category;
	this->Type = Type;
	this->Function = Function;

	Category->Block.push_back(this);
}
