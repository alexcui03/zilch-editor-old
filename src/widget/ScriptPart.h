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

class ScriptPart_BlockTab : public Widget {
	Q_OBJECT
public:
	ScriptPart_BlockTab(QWidget *parent = nullptr);
public:
	BlockTabItem *LastClicked;
	std::vector<BlockTabItem*> BlockTab;
public slots:
	void Reload();
signals:
	void reloadview(ScratchBlockCategory*);
};

class ScriptPart_BlockView : public Widget {
	Q_OBJECT
public:
	ScriptPart_BlockView(QWidget *parent = nullptr);
public slots:
	void Reload(ScratchBlockCategory *Category);
public:
	std::vector<BlockItem*> Block;
};

class ScriptPart_ScriptEdit : public Widget {
	Q_OBJECT
public:
	ScriptPart_ScriptEdit(QWidget *parent = nullptr);
public slots:
	void Reload();
};

class ScriptPart : public Widget {
public:
	ScriptPart(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public:
	ScriptPart_BlockTab *BlockTab;
	ScriptPart_BlockView *BlockView;
	ScriptPart_ScriptEdit *ScriptEdit;
};

#endif // SCRIPTPART_H
