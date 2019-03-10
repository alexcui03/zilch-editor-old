#include "ScriptPartEdit.h"

#include "../BlockItem.h"
#include "../MainWindow.h"

ScriptPartEdit::ScriptPartEdit(QWidget *parent) : Widget(parent) {

}

ScriptPartEdit::~ScriptPartEdit() {

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
