#ifndef STAGEAREA_H
#define STAGEAREA_H

#include <QPushButton>

#include "Widget.h"
#include "StageView.h"

class StageArea : public Widget {
public:
	explicit StageArea(QWidget *parent = nullptr);
public:
	QPushButton *ButtonStart;
	QPushButton *ButtonStop;
	StageView *StageView;
};

#endif // STAGEAREA_H
