#ifndef SCRATCHRESOURCE_H
#define SCRATCHRESOURCE_H

#include <vector>
#include "../util/Resource.h"

class ScratchResource {
public:
	ScratchResource();
	~ScratchResource();
	size_t LoadResourceAudio(std::string Path);
	size_t LoadResourceVideo(std::string Path);
	size_t LoadResourceBitmap(std::string Path);
	void UnloadResource(size_t Index);
public:
	std::vector<ResourceBasic*> Resource;
};

#endif // SCRATCHRESOURCE_H
