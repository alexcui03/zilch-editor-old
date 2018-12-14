#ifndef RESOURSECONTROL_H
#define RESOURSECONTROL_H

#include <cstdint>
#include <vector>
#include <string>

class ResourseBasic;
class ResourseAudio;
class ResourseVideo;
class ResoursePhoto;

union HashMD5 {
	unsigned char Byte[16];
};

class ResourseBasic {
public:
	HashMD5 Hash;
	std::string Path;
};

class ResourseAudio : public ResourseBasic {
public:
	uint64_t Size;
};

class ResourseVideo : public ResourseBasic {

};

class ResoursePhoto : public ResourseBasic {

};

#endif // RESOURSECONTROL_H
