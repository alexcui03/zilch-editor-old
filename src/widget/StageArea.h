#ifndef STAGEAREA_H
#define STAGEAREA_H

#include <QPushButton>

#include "Widget.h"
#include "StageItem.h"
#include "StageView.h"

class StageArea : public Widget {
	Q_OBJECT
public:
	explicit StageArea(QWidget *parent = nullptr);
public slots:
	void RunProgram();
public:
	QPushButton *ButtonStart;
	QPushButton *ButtonStop;
	StageItem *StageItem;
	StageView *StageView;

};

#endif // STAGEAREA_H
