#ifndef COSTUMEPARTLIST_H
#define COSTUMEPARTLIST_H

#include <vector>

#include "CostumeListItem.h"
#include "../Widget.h"

class CostumeList : public Widget {
	Q_OBJECT
public:
	CostumeList(QWidget *parent = nullptr);
	~CostumeList();
public slots:
	void reload();
public:
	std::vector<CostumeListItem*> list_items;
};

#endif // COSTUMEPARTLIST_H
