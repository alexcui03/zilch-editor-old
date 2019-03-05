#ifndef STAGEAREA_H
#define STAGEAREA_H

#include <QPushButton>

#include "Widget.h"
#include "StageView.h"

class StageArea : public Widget {
	Q_OBJECT
public:
	explicit StageArea(QWidget *parent = nullptr);
	virtual ~StageArea() override;
	virtual void reloadTranslation() override;
public slots:
	void RunProgram();
public:
	QPushButton *ButtonStart;
	QPushButton *ButtonStop;
	StageView *StageView;
};

#endif // STAGEAREA_H
