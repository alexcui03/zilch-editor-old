#ifndef SCRATCHRESOURCE_H
#define SCRATCHRESOURCE_H

#include <vector>
#include "../util/Resource.h"

class ScratchResource {
public:
	ScratchResource();
	~ScratchResource();
public:
	std::vector<ResourceBasic*> Resource;
};

#endif // SCRATCHRESOURCE_H
