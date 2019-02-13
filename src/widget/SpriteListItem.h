#ifndef SPRITELISTITEM_H
#define SPRITELISTITEM_H

#include <QLabel>

#include "ObjectListItem.h"
#include "../scratch/ScratchSprite.h"

class SpriteListItem : public ObjectListItem {
	Q_OBJECT
public:
	SpriteListItem(ScratchSprite *sprite, QWidget *parent = nullptr);
	virtual ~SpriteListItem();
public slots:
	void showInfo();
public:
	Widget *btnInfo;
};

#endif // SPRITELISTITEM_H
