#include "ScriptPart.h"
#include "MainWindow.h"
#include "../logger/Logger.h"
#include "../scratch/Scratch.h"
#include "../scratch/ScratchSprite.h"
#include "../scratch/ScratchStage.h"

ScriptPartTab::ScriptPartTab(QWidget *parent) : Widget(parent) {
	this->LastClicked = nullptr;
	this->Reload();
}

void ScriptPartTab::Reload() {
	for (auto &c : this->BlockTab) {
		delete c;
	}
	this->BlockTab.clear();
	size_t Length = ScratchMain.BlockCategory.size();
	for (size_t i = 0; i < Length; i++) {
		const auto &Temp = ScratchMain.BlockCategory[i];
		BlockTabItem *Item = new BlockTabItem(Temp, this);
		Item->move(10 + 95 * (i & 1), (static_cast<int>(i) / 2) * 23 + 7);
		Item->setText(Temp->Name.c_str());
		Item->setPalette(QPalette(QColor(Temp->Color)));
		Item->show();
		this->BlockTab.push_back(Item);
	}
	this->resize(200, (static_cast<int>(ScratchMain.BlockCategory.size()) + 1) / 2 * 24 + 14);
	this->BlockTab[0]->OnSelect();
}

ScriptPartView::ScriptPartView(QWidget *parent) : Widget(parent) {
	this->Reload(ScratchMain.BlockCategory[0]);
}

void ScriptPartView::Reload(ScratchBlockCategory *Category) {
	for (auto &c : Block) {
		delete c;
	}
	Block.clear();
	size_t Length = Category->Block.size();
	for (size_t i = 0; i < Length; i++) {
		ScratchBlock *Temp = new ScratchBlock(Category->Block[i], nullptr);
		BlockItem *Item = new BlockItem(Temp, nullptr, nullptr, this);
		Item->isViewingBlock = true;
		Item->ViewerIndex = i;
		if (Block.empty()) {
			Item->move(10, 10 + 35 * static_cast<int>(i));
		}
		else {
			Item->move(10, (*Block.rbegin())->y() + (*Block.rbegin())->height() + 10);
		}
		Item->show();
		Block.push_back(Item);
	}
}

ScriptPartEdit::ScriptPartEdit(QWidget *parent) : Widget(parent) {

}

void ScriptPartEdit::Reload() {
	for (auto c : this->children()) {
		static_cast<BlockItem*>(c)->hide();
	}
	for (auto &c : AppWindow->EditArea->Object->BlockList) {
		c->Item->show();
		for (auto &i = c->NextBlock; i != nullptr; i = i->NextBlock) {
			i->Item->show();
		}
	}
}

ScriptPart::ScriptPart(QWidget *parent) : Widget(parent) {
	BlockTab = new ScriptPartTab(this);
	BlockTab->setObjectName("EditArea_ScriptPart_BlockTab");
	BlockTab->move(0, 0);
	BlockTab->resize(200, (static_cast<int>(ScratchMain.BlockCategory.size()) + 1) / 2 * 24 + 14);

	BlockView = new ScriptPartView(this);
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

