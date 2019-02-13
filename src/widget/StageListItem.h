#ifndef STAGELISTITEM_H
#define STAGELISTITEM_H

#include <QLabel>

#include "ObjectListItem.h"
#include "../scratch/ScratchStage.h"

class StageListItem : public ObjectListItem {
public:
	StageListItem(ScratchStage *stage, QWidget *parent = nullptr);
	virtual ~StageListItem();
};

#endif // STAGELISTITEM_H
