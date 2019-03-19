#include "ScriptPart.h"
#include "../MainWindow.h"
#include "../../logger/Logger.h"
#include "../../scratch/Scratch.h"
#include "../../scratch/ScratchSprite.h"
#include "../../scratch/ScratchStage.h"

ScriptPart::ScriptPart(QWidget *parent) : Widget(parent) {
	BlockTab = new ScriptPartBlockTab(this);
	BlockTab->setObjectName("EditArea_ScriptPart_BlockTab");
	BlockTab->move(0, 0);
	BlockTab->resize(200, (static_cast<int>(ScratchMain.BlockCategory.size()) + 1) / 2 * 24 + 14);

	BlockView = new ScriptPartBlockView(this);
	BlockView->setObjectName("EditArea_ScriptPart_BlockView");
	BlockView->move(0, BlockTab->rect().bottom() + 5);
	BlockView->resize(200, this->height() - BlockView->rect().top());

	ScriptEdit = new ScriptPartEdit(this);
	ScriptEdit->setObjectName("EditArea_ScriptPart_ScriptEdit");
	ScriptEdit->move(BlockTab->rect().right(), 5);
	ScriptEdit->resize(this->width() - 205, this->height() - 10);

	connect(BlockTab, SIGNAL(reloadview(ScratchBlockCategory*)), BlockView, SLOT(Reload(ScratchBlockCategory*)));
}

void ScriptPart::resizeEvent(QResizeEvent*) {
	BlockView->resize(200, this->height() - BlockView->rect().top());
	ScriptEdit->resize(this->width() - 205, this->height() - 10);
}

