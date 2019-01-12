#include "StageView.h"
#include "SpriteItem.h"
#include "../scratch/Scratch.h"
#include "../scratch/ScratchSprite.h"
#include <QStyleOption>
#include <QPainter>

StageView::StageView(QWidget *parent):Widget(parent) {
	this->Reload();
}

QPoint StageView::ConvertXY(int x, int y) {
	return QPoint(Width / 2 + x, Height / 2 - y);
}

void StageView::Reload() {
	if (!this->Sprites.empty()) {
		for (auto &c : this->Sprites) {
			delete c;
		}
		this->Sprites.clear();
	}
	for (auto &c : ScratchMain.Stage.Sprite) {
		SpriteItem *Item = new SpriteItem(c, this);
		c->Item = Item;
		this->Sprites.push_back(Item);
		Item->show();
	}
}


