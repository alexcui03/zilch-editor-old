#include "SpriteListItem.h"
#include <QPalette>
#include <QColor>
#include "SpriteArea.h"
#include "ScriptPart.h"
#include "MainWindow.h"

/**
 * @brief SpriteListItem::SpriteListItem - Constructor.
 * @param {ScratchSprite*} Sprite - Sprite data.
 * @param {QWidget*} parent - Parent widget.
 */
SpriteListItem::SpriteListItem(ScratchSprite *Sprite, QWidget *parent) : Widget(parent) {
	this->Sprite = Sprite;

	setObjectName("SpriteListItem");
	resize(75, 75);
	setAutoFillBackground(true);
	setPalette(QPalette(QColor(0xFFB11B)));

	Text = new QLabel(this);
	Text->setObjectName("SpriteListItem_Text");
	Text->move(0, 60);
	Text->resize(75, 15);
	Text->setText(Sprite->Name.c_str());
	Text->setAlignment(Qt::AlignCenter);

	Button = new Widget(this);
	Button->setObjectName("SpriteListItem_Text");
	Button->move(3, 3);
	Button->resize(10, 10);
	Button->setAutoFillBackground(true);
	Button->setPalette(QPalette(QColor(0x66CCFF)));

	connect(this, SIGNAL(leftclicked()), SLOT(OnClick()));
	connect(Button, SIGNAL(leftclicked()), this, SLOT(ShowInfo()));
}

/**
 * @brief SpriteListItem::OnClick - Onclick event.
 */
void SpriteListItem::OnClick() {
	AppWindow->EditArea->ChangeObject(this->Sprite);
}

/**
 * @brief SpriteListItem::ShowInfo - Onclick event.
 */
void SpriteListItem::ShowInfo() {
	SpriteArea_SpriteArea *Area = dynamic_cast<SpriteArea_SpriteArea*>(parentWidget());
	for (size_t i = 0; i < Area->SpriteList.size(); i++) {
		if (Area->SpriteList[i]->Sprite->Name == Sprite->Name) {
			Area->ShowIndex = static_cast<int>(i);
			Area->RefreshList();
		}
	}
}
