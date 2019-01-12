#include "ScratchObject.h"

ScratchObject::ScratchObject(std::string Name) {
	this->Name = Name;
	auto c = ScratchCostume();
	this->CostumeList.push_back(c);
	this->CurrentCostume = 0;
}
