#include "ScratchResource.h"
#include "exception"
#include <QImage>

ScratchResource::ScratchResource() {

}

ScratchResource::~ScratchResource() {
	for (size_t i = 0; i < Resource.size(); i++) {
		delete Resource[i];
	}
	Resource.clear();
}

size_t ScratchResource::LoadResourceAudio(std::string Path) {
	///TODO: Load Audio Source
	return 0;
}

size_t ScratchResource::LoadResourceVideo(std::string Path) {
	///TODO: Load Video Source
	return 0;
}

size_t ScratchResource::LoadResourceBitmap(std::string Path) {
	QImage *Data = new QImage(Path.c_str());
	ResourceBasic *Res = new ResourceBitmap();
	Res->Data = Data;
	Res->Path = Path;
	Resource.push_back(Res);
	return 0;
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
		throw std::exception("Index out of range.");
	}
}

