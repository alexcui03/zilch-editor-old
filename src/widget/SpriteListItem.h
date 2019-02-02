#ifndef SPRITELISTITEM_H
#define SPRITELISTITEM_H

#include "Widget.h"
#include <QLabel>
#include "../scratch/ScratchSprite.h"

class SpriteListItem : public Widget {
	Q_OBJECT
public:
	SpriteListItem(ScratchSprite *Sprite, QWidget *parent = nullptr);
public slots:
	void OnClick();
	void ShowInfo();
public:
	bool Selected;
	ScratchSprite *Sprite;
	QLabel *Text;
	Widget *Button;
};

#endif // SPRITELISTITEM_H
