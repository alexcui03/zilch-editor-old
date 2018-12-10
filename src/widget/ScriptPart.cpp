#include "ScriptPart.h"
#include "../scratch/Scratch.h"
#include "../logger/Logger.h"
#include <QDebug>

ScriptPart_BlockTab::ScriptPart_BlockTab(QWidget *parent):Widget(parent) {
	LastClicked = nullptr;
	connect(this, SIGNAL(reload()), SLOT(Reload()));
	emit reload();
}

void ScriptPart_BlockTab::Reload() {
	for (auto &c : BlockTab) {
		delete c;
	}
	BlockTab.clear();
	size_t Length = ScratchMain.BlockCategory.size();
	for (size_t i = 0; i < Length; i++) {
		const auto &Temp = ScratchMain.BlockCategory[i];
		BlockTabItem *Item = new BlockTabItem(Temp, this);
		Item->move(10 + 95 * (i & 1), (static_cast<int>(i) / 2) * 23 + 7);
		Item->setText(Temp->Name.c_str());
		Item->setPalette(QPalette(QColor(Temp->Color)));
		Item->show();
		BlockTab.push_back(Item);
	}
	resize(200, (static_cast<int>(ScratchMain.BlockCategory.size()) + 1) / 2 * 24 + 14);
	emit BlockTab[0]->leftclicked();
}

ScriptPart_BlockView::ScriptPart_BlockView(QWidget *parent):Widget(parent) {
	connect(this, SIGNAL(reload(ScratchBlockCategory*)), SLOT(Reload(ScratchBlockCategory*)));
	emit reload(ScratchMain.BlockCategory[0]);
}

void ScriptPart_BlockView::Reload(ScratchBlockCategory *Category) {
	for (auto &c : Block) {
		delete c;
	}
	Block.clear();
	size_t Length = Category->Block.size();
	for (size_t i = 0; i < Length; i++) {
		const auto &Temp = Category->Block[i];
		BlockItem *Item = new BlockItem(Temp, nullptr, nullptr, this);
		Item->isViewingBlock = true;
		Item->ViewerIndex = i;
		if (Block.empty()) {
			Item->move(10, 10 + 35 * static_cast<int>(i));
		}
		else {
			Item->move(10, (*Block.rbegin())->rect().bottom() + 20);
		}
		Item->show();
		Block.push_back(Item);
	}
}

ScriptPart_ScriptEdit::ScriptPart_ScriptEdit(QWidget *parent):Widget(parent) {

}

ScriptPart::ScriptPart(QWidget *parent):Widget(parent) {
	BlockTab = new ScriptPart_BlockTab(this);
	BlockTab->setObjectName("EditArea_ScriptPart_BlockTab");
	BlockTab->move(0, 0);
	BlockTab->resize(200, (static_cast<int>(ScratchMain.BlockCategory.size()) + 1) / 2 * 24 + 14);

	BlockView = new ScriptPart_BlockView(this);
	BlockView->setObjectName("EditArea_ScriptPart_BlockView");
	BlockView->move(0, BlockTab->rect().bottom() + 5);
	BlockView->resize(200, this->height() - BlockView->rect().top());

	ScriptEdit = new ScriptPart_ScriptEdit(this);
	ScriptEdit->setObjectName("EditArea_ScriptPart_ScriptEdit");
	ScriptEdit->move(BlockTab->rect().right(), 5);
	ScriptEdit->resize(this->width() - 205, this->height() - 10);

	connect(BlockTab, SIGNAL(reloadview(ScratchBlockCategory*)), BlockView, SLOT(Reload(ScratchBlockCategory*)));
}

void ScriptPart::resizeEvent(QResizeEvent*) {
	BlockView->resize(200, this->height() - BlockView->rect().top());
	ScriptEdit->resize(this->width() - 205, this->height() - 10);
}

