#ifndef UPDATER_H
#define UPDATER_H

#include <vector>
#include <string>

#include "../util/VersionInfo.h"

namespace Updater {

struct UpdateSource {
	std::string name;
	std::string url;
};

extern std::vector<UpdateSource> source_list;
extern std::string select_source;

void loadSourceListFromConfig();
void getServerData();

}

#endif // UPDATER_H
