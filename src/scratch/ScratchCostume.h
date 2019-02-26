#ifndef SCRATCHCOSTUME_H
#define SCRATCHCOSTUME_H

#include <string>
#include "ScratchResource.h"

class ScratchCostume {
public:
	ScratchCostume();
	ScratchCostume(ResourcePhoto *resource);
public:
	std::string name;
	ResourcePhoto *resource;
};

#endif // SCRATCHCOSTUME_H
