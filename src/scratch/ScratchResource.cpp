#include "ScratchResource.h"
#include <exception>
#include <QImage>

ScratchResource::ScratchResource() {

}

ScratchResource::~ScratchResource() {
	for (size_t i = 0; i < Resource.size(); i++) {
		delete Resource[i];
	}
	Resource.clear();
}

ResourceAudio *ScratchResource::LoadResourceAudio(std::string) {
	///TODO: Load Audio Source
	return nullptr;
}

ResourceVideo *ScratchResource::LoadResourceVideo(std::string) {
	///TODO: Load Video Source
	return nullptr;
}

ResourcePhoto *ScratchResource::LoadResourcePhoto(std::string Path) {
	QImage *Data = new QImage(Path.c_str());
	ResourcePhoto *Res = new ResourcePhoto();
	Res->Data = Data;
	Res->Path = Path;
	Resource.push_back(Res);
	return Res;
}

void ScratchResource::UnloadResource(size_t Index) {
	if (Resource.size() > Index) {
		delete Resource[Index];
		auto Temp = Resource.begin();
		while (Index-- > 0) {
			Temp++;
		}
		Resource.erase(Temp);
	}
	else {
		//throw std::exception("Index out of range.");
	}
}

