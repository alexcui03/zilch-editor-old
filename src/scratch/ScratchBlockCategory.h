#ifndef SCRATCHBLOCKCATEGORY_H
#define SCRATCHBLOCKCATEGORY_H

#include <string>
#include <vector>

#include "ScratchBlock.h"

class ScratchBlockCategory {
public:
	ScratchBlockCategory(std::string Name, unsigned int Color);
public:
	std::vector<ScratchBlock*> Block;
	std::string Name;
	unsigned int Color;
};

#endif // SCRATCHBLOCKCATEGORY_H
