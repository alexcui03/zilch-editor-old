#ifndef COSTUMELISTITEM_H
#define COSTUMELISTITEM_H

#include <QLabel>

#include "../Widget.h"
#include "../../scratch/ScratchCostume.h"

class CostumeListItem : public Widget {
	Q_OBJECT
public:
	CostumeListItem(ScratchCostume *costume, QWidget *parent = nullptr);
	~CostumeListItem();
public slots:
	void select();
public:
	static CostumeListItem *selected_item;
	ScratchCostume *costume;
	QLabel *label;
};

#endif // COSTUMELISTITEM_H
