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

class SpriteArea;
class SpriteArea_StageArea;
class SpriteArea_SpriteArea;
class SpriteArea_SpriteArea_TopBar;

class SpriteArea : public Widget {
public:
	explicit SpriteArea(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public:
	SpriteArea_StageArea *Stage;
	SpriteArea_SpriteArea *Sprite;
};

class SpriteArea_StageArea : public Widget {
public:
	explicit SpriteArea_StageArea(QWidget *parent = nullptr);
public:

};

class SpriteArea_SpriteArea : public Widget {
	Q_OBJECT
public:
	explicit SpriteArea_SpriteArea(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public slots:
	void RefreshList();
	void BackToList();
signals:
	void refresh();
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

class SpriteArea_SpriteArea_TopBar : public Widget {
public:
	explicit SpriteArea_SpriteArea_TopBar(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public:
	QLabel *TextSprite;
	QLabel *TextNewSprite;
	QPushButton *ButtonNewSprite;
};

#endif // SPRITEAREA_H
