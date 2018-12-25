#ifndef RESOURCE_H
#define RESOURCE_H

#include <cstdint>
#include <vector>
#include <string>

union HashMD5 {
	unsigned char Byte[16];
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

class ResourceBitmap : public ResourceBasic {
public:
	unsigned int Height;
	unsigned int Width;
};

#endif // RESOURCE_H
