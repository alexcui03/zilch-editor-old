#ifndef STAGEVIEW_H
#define STAGEVIEW_H

#include <vector>

#include "Widget.h"
#include "SpriteItem.h"

class StageView : public Widget {
public:
	explicit StageView(QWidget *parent = nullptr);
	QPoint ConvertXY(int x, int y);
public:
	int Width;
	int Height;
	std::vector<SpriteItem*> Sprites;
};

#endif // STAGEVIEW_H
