#ifndef SPRITEITEM_H
#define SPRITEITEM_H

#include "Widget.h"
#include "../scratch/ScratchSprite.h"

class SpriteItem : public Widget {
public:
	explicit SpriteItem(ScratchSprite *Sprite, QWidget *parent = nullptr);
public:
	ScratchSprite *Sprite;
};

#endif // SPRITEITEM_H
