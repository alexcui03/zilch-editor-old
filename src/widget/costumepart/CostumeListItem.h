#ifndef COSTUMELISTITEM_H
#define COSTUMELISTITEM_H

#include <QLabel>

#include "../Widget.h"
#include "../../scratch/ScratchCostume.h"

class CostumeListItem : public Widget {
public:
	CostumeListItem(ScratchCostume *costume, QWidget *parent = nullptr);
	~CostumeListItem();
public:
	ScratchCostume *costume;
	QLabel *label;
};

#endif // COSTUMELISTITEM_H
