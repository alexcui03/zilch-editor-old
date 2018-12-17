#ifndef STAGEVIEW_H
#define STAGEVIEW_H

#include "Widget.h"

class StageView : public Widget {
public:
	explicit StageView(QWidget *parent = nullptr);
	QPoint ConvertXY(int x, int y);
public:
	int Width;
	int Height;
	Widget *TestSprite;
};

#endif // STAGEVIEW_H
