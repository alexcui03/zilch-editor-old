#ifndef COSTUMEPART_H
#define COSTUMEPART_H

#include "CostumeNew.h"
#include "CostumeList.h"
#include "CostumeView.h"
#include "../Widget.h"

class CostumePart : public Widget {
public:
	explicit CostumePart(QWidget *parent = nullptr);
	~CostumePart();
	void resizeEvent(QResizeEvent* size);
public:
	int index;
	CostumeNew *costume_new;
	CostumeList *costume_list;
	CostumeView *costume_view;
};

#endif // COSTUMEPART_H
