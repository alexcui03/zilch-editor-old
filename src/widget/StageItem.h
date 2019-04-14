#ifndef STAGEITEM_H
#define STAGEITEM_H

#include "ObjectItem.h"
#include "../scratch/ScratchStage.h"

class StageItem : public ObjectItem {
public:
	explicit StageItem(ScratchStage *stage, QWidget *parent = nullptr);
	~StageItem();
};

#endif // STAGEITEM_H
