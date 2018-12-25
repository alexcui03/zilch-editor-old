#include "ScratchResource.h"

ScratchResource::ScratchResource() {

}

ScratchResource::~ScratchResource() {
	for (size_t i = 0; i < Resource.size(); i++) {
		delete Resource[i];
	}
	Resource.clear();
}
