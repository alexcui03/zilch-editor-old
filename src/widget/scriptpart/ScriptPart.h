#ifndef SCRIPTPART_H
#define SCRIPTPART_H

#include <vector>

#include <QWidget>
#include <QResizeEvent>
#include <QLabel>
#include <QPushButton>

#include "ScriptPartBlockTab.h"
#include "ScriptPartBlockView.h"
#include "ScriptPartEdit.h"
#include "../Widget.h"

class ScriptPart : public Widget {
public:
	ScriptPart(QWidget *parent = nullptr);
	void resizeEvent(QResizeEvent* size);
public:
	int index;
	ScriptPartBlockTab *BlockTab;
	ScriptPartBlockView *BlockView;
	ScriptPartEdit *ScriptEdit;
};

#endif // SCRIPTPART_H
