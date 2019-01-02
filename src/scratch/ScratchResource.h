#ifndef SCRATCHRESOURCE_H
#define SCRATCHRESOURCE_H

#include <vector>
#include "../util/Resource.h"

class ScratchResource {
public:
	ScratchResource();
	~ScratchResource();
	ResourceAudio *LoadResourceAudio(std::string Path);
	ResourceVideo *LoadResourceVideo(std::string Path);
	ResourcePhoto *LoadResourcePhoto(std::string Path);
	void UnloadResource(size_t Index);
public:
	std::vector<ResourceBasic*> Resource;
};

#endif // SCRATCHRESOURCE_H
