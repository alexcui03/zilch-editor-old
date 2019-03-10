#include "ScriptPartBlockTab.h"

#include "../../scratch/Scratch.h"

ScriptPartBlockTab::ScriptPartBlockTab(QWidget *parent) : Widget(parent) {
	this->LastClicked = nullptr;
	this->Reload();
}

void ScriptPartBlockTab::Reload() {
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
