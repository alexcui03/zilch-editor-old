#ifndef VERSIONINFO_H
#define VERSIONINFO_H

#include <string>

enum class VersionType {
	ALPHA	= 0b0001,
	BETA	= 0b0010,
	RELEASE	= 0b0100,
};

class VersionInfo {
public:
	VersionInfo();
	~VersionInfo();
	bool operator>(VersionInfo &op);
	bool operator<(VersionInfo &op);
	bool operator==(VersionInfo &op);
	bool operator!=(VersionInfo &op);
public:
	VersionType type;
	unsigned int major;
	unsigned int minor;
	unsigned int revision;
	unsigned int build;
	std::string url;
};

#endif // VERSIONINFO_H
