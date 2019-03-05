#ifndef EDITAREA_H
#define EDITAREA_H

#include <QWidget>
#include <QTabWidget>

#include "Widget.h"
#include "ScriptPart.h"
#include "costumepart/CostumePart.h"

class EditArea : public Widget {
public:
	explicit EditArea(QWidget *parent = nullptr);
	~EditArea() override;
	void reloadTranslation() override;
	void resizeEvent(QResizeEvent *size) override;
	void ChangeObject(ScratchObject *Object);
public:
	ScratchObject *Object;
	QTabWidget *TabWidget;
	ScriptPart *ScriptPart;
	CostumePart *CostumePart;
};

#endif // EDITAREA_H
