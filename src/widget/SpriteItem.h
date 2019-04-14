#ifndef SPRITEITEM_H
#define SPRITEITEM_H

#include "ObjectItem.h"
#include "../scratch/ScratchSprite.h"

class SpriteItem : public ObjectItem {
public:
	explicit SpriteItem(ScratchSprite *sprite, QWidget *parent = nullptr);
	~SpriteItem();
	void reload();
};

#endif // SPRITEITEM_H
