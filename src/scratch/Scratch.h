#ifndef SCRATCH_H
#define SCRATCH_H

#include <vector>
#include <string>

#include "ScratchBlockCategory.h"
#include "ScratchBlock.h"

class Scratch {
public:
	Scratch();
public:
	std::vector<ScratchBlockCategory*> BlockCategory;
	std::vector<ScratchBlock*> Block;
};

extern Scratch ScratchMain;

#endif // SCRATCH_H
