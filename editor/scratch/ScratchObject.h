#ifndef SCRATCHOBJECT_H
#define SCRATCHOBJECT_H

#include <string>
#include <vector>
#include "ScratchBlock.h"

class ScratchObject {
public:
	ScratchObject(std::string Name);
public:
	std::string Name;
	std::vector<size_t> Costumes;
	std::vector<size_t> Sounds;
	std::vector<ScratchBlock*> Blocks;
};

#endif // SCRATCHOBJECT_H
