#ifndef SPRITEAREA_H
#define SPRITEAREA_H

#include "Widget.h"

#include <vector>

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>

#include "SpriteListItem.h"
#include "StageListItem.h"

class SpriteArea_StageArea : public Widget {
public:
	explicit SpriteArea_StageArea(QWidget *parent = nullptr);
	~SpriteArea_StageArea() override;
	void reloadTranslation() override;
public:
	StageListItem *Stage;
};

class SpriteArea_SpriteArea_TopBar : public Widget {
	Q_OBJECT
public:
	explicit SpriteArea_SpriteArea_TopBar(QWidget *parent = nullptr);
	~SpriteArea_SpriteArea_TopBar() override;
	void reloadTranslation() override;
	void resizeEvent(QResizeEvent* size) override;
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
	~SpriteArea_SpriteArea() override;
	void reloadTranslation() override;
	void resizeEvent(QResizeEvent* size) override;
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
	~SpriteArea() override;
	void reloadTranslation() override;
	void resizeEvent(QResizeEvent* size) override;
public:
	SpriteArea_StageArea *Stage;
	SpriteArea_SpriteArea *Sprite;
};

#endif // SPRITEAREA_H
