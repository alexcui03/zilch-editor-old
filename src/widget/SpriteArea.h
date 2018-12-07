#ifndef SPRITEAREA_H
#define SPRITEAREA_H

#include "Widget.h"

class SpriteArea : public Widget {
public:
	explicit SpriteArea(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
};

#endif // SPRITEAREA_H
