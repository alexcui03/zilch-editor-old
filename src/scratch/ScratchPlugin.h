#ifndef SCRATCHPLUGIN_H
#define SCRATCHPLUGIN_H

#include <string>

class ScratchPlugin {
public:
	ScratchPlugin(std::string Name);
	~ScratchPlugin();
public:
	std::string Name;
	std::string Title;
	std::string Description;
	bool isEnable;
};

#endif // SCRATCHPLUGIN_H
