#include "SpriteListItem.h"

#include <QPalette>
#include <QColor>
#include <QStyle>

#include "SpriteArea.h"
#include "MainWindow.h"

SpriteListItem::SpriteListItem(ScratchSprite *sprite, QWidget *parent) : ObjectListItem(sprite, parent) {
	this->resize(75, 75);

	this->text->move(0, 57);
	this->text->resize(75, 15);

	this->btnInfo = new Widget(this);
	this->btnInfo->setObjectName("SpriteListItem_Info");
	this->btnInfo->move(5, 5);
	this->btnInfo->resize(16, 16);

	connect(btnInfo, SIGNAL(leftclicked()), this, SLOT(showInfo()));
}

SpriteListItem::~SpriteListItem() {

}

void SpriteListItem::showInfo() {
	SpriteArea_SpriteArea *Area = dynamic_cast<SpriteArea_SpriteArea*>(parentWidget());
	for (size_t i = 0; i < Area->SpriteList.size(); i++) {
		if (Area->SpriteList[i]->object->Name == object->Name) {
			Area->ShowIndex = static_cast<int>(i);
			Area->RefreshList();
		}
	}
}
