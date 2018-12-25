#ifndef SCRATCHBLOCKCATEGORY_H
#define SCRATCHBLOCKCATEGORY_H

#include <string>
#include <vector>

#include "ScratchBlockPrototype.h"

class ScratchBlockCategory {
public:
	ScratchBlockCategory(std::string Name, unsigned int Color);
	~ScratchBlockCategory();
public:
	std::vector<ScratchBlockPrototype*> Block;
	std::string Name;
	unsigned int Color;
};

#endif // SCRATCHBLOCKCATEGORY_H
