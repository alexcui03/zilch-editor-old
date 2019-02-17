#ifndef SPRITEAREA_H
#define SPRITEAREA_H

#include "Widget.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <vector>
#include "SpriteListItem.h"
#include "StageListItem.h"

class SpriteArea_StageArea : public Widget {
public:
	explicit SpriteArea_StageArea(QWidget *parent = nullptr);
public:
	StageListItem *Stage;
};

class SpriteArea_SpriteArea_TopBar : public Widget {
	Q_OBJECT
public:
	explicit SpriteArea_SpriteArea_TopBar(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public slots:
	void NewSprite();
public:
	QLabel *TextSprite;
	QLabel *TextNewSprite;
	QPushButton *ButtonNewSprite;
};

class SpriteArea_SpriteArea : public Widget {
	Q_OBJECT
public:
	explicit SpriteArea_SpriteArea(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
	void RefreshList();
	void ReloadList();
public slots:
	void BackToList();
public:
	SpriteArea_SpriteArea_TopBar *TopBar;
	std::vector<SpriteListItem*> SpriteList;
	int ShowIndex;
	// Sprite information
	QPushButton *ButtonBack;
	QLabel *View;
	QLineEdit *Name;
	QLabel *Position;
	QLabel *Direction;
	QCheckBox *Draggable;
	QCheckBox *Show;
};

class SpriteArea : public Widget {
public:
	explicit SpriteArea(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public:
	SpriteArea_StageArea *Stage;
	SpriteArea_SpriteArea *Sprite;
};

#endif // SPRITEAREA_H
