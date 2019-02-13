#ifndef OBJECTLISTITEM_H
#define OBJECTLISTITEM_H

#include <QLabel>

#include "Widget.h"
#include "../scratch/ScratchObject.h"

class ObjectListItem : public Widget {
	Q_OBJECT
public:
	ObjectListItem(ScratchObject *object, QWidget *parent = nullptr);
	virtual ~ObjectListItem() = 0;
public slots:
	void select();
public:
	bool is_selected;
	ScratchObject *object;
	QLabel *text;
private:
	static ObjectListItem *selected_item;
};

#endif // OBJECTLISTITEM_H
