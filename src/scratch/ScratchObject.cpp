#include "ScratchObject.h"

#include "Scratch.h"

ScratchObject::ScratchObject(std::string Name) {
	this->Item = nullptr;
	this->Name = Name;
	if (Name == "Stage") {
		auto res = ScratchMain.ResourceControl.LoadResourcePhoto("./asset/backdrop.png");
		auto c = ScratchCostume(res);
		this->CostumeList.push_back(c);
		this->CurrentCostume = 0;
	}
	else {
		auto c = ScratchCostume();
		this->CostumeList.push_back(c);
		this->CurrentCostume = 0;
	}
}
