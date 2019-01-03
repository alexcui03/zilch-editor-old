#ifndef SCRATCHOBJECT_H
#define SCRATCHOBJECT_H

#include <string>
#include <vector>
#include "ScratchBlock.h"
#include "ScratchCostume.h"

class ScratchObject {
public:
	ScratchObject(std::string Name);
public:
	std::string Name;
	size_t CurrentCostume;
	std::vector<ScratchCostume> CostumeList;
	std::vector<size_t> Sounds;
	std::vector<ScratchBlock*> BlockList;
};

#endif // SCRATCHOBJECT_H
