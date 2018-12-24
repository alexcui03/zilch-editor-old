#ifndef RESOURCE_H
#define RESOURCE_H

#include <cstdint>
#include <vector>
#include <string>

class ResourceBasic;
class ResourceAudio;
class ResourceVideo;
class ResourcePhoto;

union HashMD5 {
	unsigned char Byte[16];
};

class ResourceBasic {
public:
	HashMD5 Hash;
	std::string Path;
};

class ResourceAudio : public ResourceBasic {
public:
	uint64_t Size;
};

class ResourceVideo : public ResourceBasic {

};

class ResourcePhoto : public ResourceBasic {

};

#endif // RESOURCE_H
