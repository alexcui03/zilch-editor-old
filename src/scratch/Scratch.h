#ifndef SCRATCH_H
#define SCRATCH_H

#include <vector>
#include <string>

#include "ScratchBlockCategory.h"
#include "ScratchBlockPrototype.h"
#include "ScratchStage.h"
#include "ScratchResource.h"

class Scratch {
public:
	Scratch();
	~Scratch();
	void ProgramRun();
	void ProgramStop();
public:
	std::vector<ScratchBlockCategory*> BlockCategory;
	std::vector<ScratchBlockPrototype*> Block;
	ScratchResource ResourceControl;
	ScratchStage Stage;
};

extern Scratch ScratchMain;

#endif // SCRATCH_H
