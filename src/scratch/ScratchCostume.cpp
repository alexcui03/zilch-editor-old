#include "ScratchCostume.h"
#include "Scratch.h"

/**
 * Default constructor.
 */
ScratchCostume::ScratchCostume() {
	this->resource = ScratchMain.ResourceControl.LoadResourcePhoto("./asset/0.png");
}

/**
 * Constructor.
 * resource - pointer to resource
 */
ScratchCostume::ScratchCostume(ResourcePhoto *resource) {
	this->resource = resource;
}
