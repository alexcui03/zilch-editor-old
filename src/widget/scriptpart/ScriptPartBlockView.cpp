#include "ScriptPartBlockView.h"

#include "../../scratch/Scratch.h"

ScriptPartBlockView::ScriptPartBlockView(QWidget *parent) : Widget(parent) {
	this->Reload(ScratchMain.BlockCategory[0]);
}

ScriptPartBlockView::~ScriptPartBlockView() {

}

void ScriptPartBlockView::Reload(ScratchBlockCategory *Category) {
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
