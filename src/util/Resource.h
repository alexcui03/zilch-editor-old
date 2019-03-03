#ifndef RESOURCE_H
#define RESOURCE_H

#include <cstdint>
#include <vector>
#include <string>

union HashMD5 {
	unsigned char byte[16];
	uint16_t data;
};

class ResourceBasic {
public:
	ResourceBasic();
	~ResourceBasic();
public:
	HashMD5 Hash;
	std::string Path;
	void *Data;
};

class ResourceAudio : public ResourceBasic {
public:
	unsigned int Length;
};

class ResourceVideo : public ResourceBasic {
public:
	unsigned int Length;
	unsigned int Height;
	unsigned int Width;
	unsigned int FPS;
};

class ResourcePhoto : public ResourceBasic {
public:
	unsigned int Height;
	unsigned int Width;
};

#endif // RESOURCE_H
