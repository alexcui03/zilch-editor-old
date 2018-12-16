#ifndef SCRATCH_H
#define SCRATCH_H

#include <vector>
#include <string>

#include "ScratchBlockCategory.h"
#include "ScratchBlockPrototype.h"
#include "ScratchStage.h"

class Scratch {
public:
	Scratch();
	void ProgramRun();
	void ProgramStop();
public:
	std::vector<ScratchBlockCategory*> BlockCategory;
	std::vector<ScratchBlockPrototype*> Block;
	ScratchStage Stage;
};

extern Scratch ScratchMain;

#endif // SCRATCH_H
