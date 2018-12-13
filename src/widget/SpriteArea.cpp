#include "SpriteArea.h"
#include "../translator/Translator.h"
#include "../scratch/Scratch.h"

/**
 * @brief SpriteArea::SpriteArea - Constructor.
 * @param {QWidget*} parent - Parent widget.
 */
SpriteArea::SpriteArea(QWidget *parent) : Widget(parent) {
	Stage = new SpriteArea_StageArea(this);
	Stage->setObjectName("SpriteArea_Stage");
	Stage->move(0, 0);
	//Stage->resize(80, height());

	Sprite = new SpriteArea_SpriteArea(this);
	Sprite->setObjectName("SpriteArea_Sprite");
	Sprite->move(80, 0);
	//Sprite->resize(width() - 80, height());
}

/**
 * @brief SpriteArea::resizeEvent - Resize event.
 */
void SpriteArea::resizeEvent(QResizeEvent *) {
	Stage->resize(80, height());
	Sprite->resize(width() - 80, height());
}

/**
 * @brief SpriteArea_StageArea::SpriteArea_StageArea - Constructor.
 * @param {QWidget*} parent - Parent widget.
 */
SpriteArea_StageArea::SpriteArea_StageArea(QWidget *parent) : Widget(parent) {

}

/**
 * @brief SpriteArea_SpriteArea::SpriteArea_SpriteArea - Constructor.
 * @param {QWidget*} parent - Parent widget.
 */
SpriteArea_SpriteArea::SpriteArea_SpriteArea(QWidget *parent) : Widget(parent) {
	ShowIndex = -1;

	TopBar = new SpriteArea_SpriteArea_TopBar(this);
	TopBar->setObjectName("SpriteArea_SpriteArea_TopBar");
	TopBar->move(0, 0);
	//TopBar->resize(width(), 20);

	ButtonBack = new QPushButton(this);
	ButtonBack->setObjectName("SpriteArea_SpriteArea_ButtonBack");
	ButtonBack->move(5, 35);
	ButtonBack->resize(20, 20);

	for (auto &c : ScratchMain.Stage.Sprite) {
		SpriteListItem *Item = new SpriteListItem(c, this);
		SpriteList.push_back(Item);
	}

	connect(this, SIGNAL(refresh()), SLOT(RefreshList()));
	connect(ButtonBack, SIGNAL(clicked()), this, SLOT(BackToList()));
	emit refresh();
}

/**
 * @brief SpriteArea_SpriteArea::RefreshList - Refresh view.
 */
void SpriteArea_SpriteArea::RefreshList() {
	if (ShowIndex == -1) {
		ButtonBack->hide();
		for (size_t i = 0; i < SpriteList.size(); i++) {
			SpriteList[i]->move((static_cast<int>(i) % 5) * 79 + 4, (static_cast<int>(i) / 5) * 79 + 34);
			SpriteList[i]->show();
		}
	}
	else {
		for (size_t i = 0; i < SpriteList.size(); i++) {
			SpriteList[i]->hide();
		}
		ButtonBack->show();
		///TODO: Show sprite info.
	}
}

/**
 * @brief SpriteArea_SpriteArea::BackToList - Refresh view.
 */
void SpriteArea_SpriteArea::BackToList() {
	ShowIndex = -1;
	RefreshList();
}

/**
 * @brief SpriteArea_SpriteArea::resizeEvent - Resize event.
 */
void SpriteArea_SpriteArea::resizeEvent(QResizeEvent*) {
	TopBar->resize(width(), 30);
}

/**
 * @brief SpriteArea_SpriteArea_TopBar::SpriteArea_SpriteArea_TopBar - Constructor.
 * @param {QWidget*} parent - Parent widget.
 */
SpriteArea_SpriteArea_TopBar::SpriteArea_SpriteArea_TopBar(QWidget *parent) : Widget(parent) {
	TextSprite = new QLabel(this);
	TextSprite->setObjectName("SpriteArea_SpriteArea_TopBar_TextSprite");
	TextSprite->setText(AppTranslator["spritearea_sprite_topbar_sprites"].c_str());
	TextSprite->move(10, 5);
	//TextSprite->adjustSize();

	ButtonNewSprite = new QPushButton(this);
	ButtonNewSprite->setObjectName("SpriteArea_SpriteArea_TopBar_ButtonNewSprite");
	ButtonNewSprite->move(370, 5);
	ButtonNewSprite->resize(20, 20);

	TextNewSprite = new QLabel(this);
	TextNewSprite->setObjectName("SpriteArea_SpriteArea_TopBar_TextNewSprite");
	TextNewSprite->setText(AppTranslator["spritearea_sprite_topbar_newsprite"].c_str());
	TextNewSprite->adjustSize();
	TextNewSprite->move(380 - ButtonNewSprite->width() - TextNewSprite->width(), 5);
}

/**
 * @brief SpriteArea_SpriteArea_TopBar::resizeEvent - Resize event.
 */
void SpriteArea_SpriteArea_TopBar::resizeEvent(QResizeEvent*) {
	TextSprite->adjustSize();
	TextNewSprite->adjustSize();
	TextNewSprite->move(380 - ButtonNewSprite->width() - TextNewSprite->width(), 5);
}


