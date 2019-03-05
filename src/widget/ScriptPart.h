#ifndef SCRIPTPART_H
#define SCRIPTPART_H

#include <vector>

#include <QWidget>
#include <QResizeEvent>
#include <QLabel>
#include <QPushButton>

#include "Widget.h"
#include "BlockItem.h"
#include "BlockTabItem.h"
#include "../scratch/ScratchObject.h"

class ScriptPartTab : public Widget {
	Q_OBJECT
public:
	ScriptPartTab(QWidget *parent = nullptr);
public:
	BlockTabItem *LastClicked;
	std::vector<BlockTabItem*> BlockTab;
public slots:
	void Reload();
signals:
	void reloadview(ScratchBlockCategory*);
};

class ScriptPartView : public Widget {
	Q_OBJECT
public:
	ScriptPartView(QWidget *parent = nullptr);
public slots:
	void Reload(ScratchBlockCategory *Category);
public:
	std::vector<BlockItem*> Block;
};

class ScriptPartEdit : public Widget {
	Q_OBJECT
public:
	ScriptPartEdit(QWidget *parent = nullptr);
public slots:
	void Reload();
};

class ScriptPart : public Widget {
public:
	ScriptPart(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public:
	int index;
	ScriptPartTab *BlockTab;
	ScriptPartView *BlockView;
	ScriptPartEdit *ScriptEdit;
};

#endif // SCRIPTPART_H
