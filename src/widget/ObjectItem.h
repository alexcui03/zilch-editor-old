#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include <QLabel>

#include "Widget.h"
#include "../scratch/ScratchObject.h"

class ObjectItem : public Widget {
public:
	explicit ObjectItem(ScratchObject *object, QWidget *parent = nullptr);
	~ObjectItem();
	void reload();
public:
	ScratchObject *object;
	QLabel *label;
};

#endif // OBJECTITEM_H
