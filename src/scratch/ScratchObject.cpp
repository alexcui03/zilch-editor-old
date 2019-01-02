#include "ScratchObject.h"

ScratchObject::ScratchObject(std::string Name) {
	this->Name = Name;
	this->Costumes.push_back(ScratchCostume());
}
