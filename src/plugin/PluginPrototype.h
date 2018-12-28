#ifndef PLUGINPROTOTYPE_H
#define PLUGINPROTOTYPE_H

#include <string>
#include "PluginBase.h"

class PluginPrototype {
public:
	PluginPrototype();
	~PluginPrototype();
public:
	std::string Name;
	std::string Description;
	PluginBase *Plugin;
};

#endif // PLUGINPROTOTYPE_H
