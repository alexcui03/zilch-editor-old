#include "ScratchObject.h"

ScratchObject::ScratchObject(std::string Name) {
	this->Name = Name;
	this->CostumeList.push_back(ScratchCostume());
	this->CurrentCostume = 0;
}
