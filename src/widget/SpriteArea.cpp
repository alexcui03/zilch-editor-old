#include "SpriteArea.h"
#include "MainWindow.h"
#include "../translator/Translator.h"
#include "../scratch/Scratch.h"
#include "../logger/Logger.h"

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

SpriteArea::~SpriteArea() {
	delete this->Stage;
	delete this->Sprite;
}

void SpriteArea::reloadTranslation() {
	this->Stage->reloadTranslation();
	this->Sprite->reloadTranslation();
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
	this->Stage = new StageListItem(&ScratchMain.Stage, this);
	this->Stage->move(3, 15);
	ObjectListItem::selected_item = Stage;
	this->Stage->is_selected = true;
	this->Stage->setObjectName("ObjectListItem-Select");
}

SpriteArea_StageArea::~SpriteArea_StageArea() {
	delete this->Stage;
}

void SpriteArea_StageArea::reloadTranslation() {
	this->Stage->reloadTranslation();
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

	// Sprite information
	ButtonBack = new QPushButton(this);
	ButtonBack->setObjectName("SpriteArea_SpriteArea_ButtonBack");
	ButtonBack->move(5, 35);
	ButtonBack->resize(20, 20);
	connect(ButtonBack, SIGNAL(clicked()), this, SLOT(BackToList()));

	View = new QLabel(this);
	View->setObjectName("SpriteArea_SpriteArea_View");
	View->move(30, 35);
	View->resize(64, 64);
	//Test:
	View->setAutoFillBackground(true);
	View->setPalette(QPalette(QColor(0xFFB11B)));

	Name = new QLineEdit(this);
	Name->setObjectName("SpriteArea_SpriteArea_LineEdit");
	Name->move(100, 35);
	Name->resize(200, 25);

	Position = new QLabel(this);
	Position->setObjectName("SpriteArea_SpriteArea_Position");
	Position->move(100, 65);
	Position->resize(200, 25);
	Position->setText("X:0 Y:0");

	Direction = new QLabel(this);
	Direction->setObjectName("SpriteArea_SpriteArea_Direction");
	Direction->move(100, 95);
	Direction->resize(200, 25);
	Direction->setText("Direction: 90°");

	Draggable = new QCheckBox(this);
	Draggable->setObjectName("SpriteArea_SpriteArea_Draggable");
	Draggable->move(100, 125);
	Draggable->resize(200, 25);
	Draggable->setText("Draggable:");

	Show = new QCheckBox(this);
	Show->setObjectName("SpriteArea_SpriteArea_Show");
	Show->move(100, 155);
	Show->resize(200, 25);
	Show->setText("Show:");

	ReloadList();
	RefreshList();
}

SpriteArea_SpriteArea::~SpriteArea_SpriteArea() {
	delete this->TopBar;
	delete this->ButtonBack;
	delete this->View;
	delete this->Name;
	delete this->Position;
	delete this->Direction;
	delete this->Draggable;
	delete this->Show;
}

void SpriteArea_SpriteArea::reloadTranslation() {
	this->TopBar->reloadTranslation();
}

/**
 * @brief SpriteArea_SpriteArea::RefreshList - Refresh view.
 */
void SpriteArea_SpriteArea::RefreshList() {
	if (ShowIndex == -1) {
		ButtonBack->hide();
		View->hide();
		Name->hide();
		Position->hide();
		Direction->hide();
		Draggable->hide();
		Show->hide();
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
		View->show();
		Name->setText(SpriteList[static_cast<size_t>(ShowIndex)]->object->Name.c_str());
		Name->show();
		Position->show();
		Direction->show();
		Draggable->show();
		Show->show();
	}
}

void SpriteArea_SpriteArea::ReloadList() {
	if (!SpriteList.empty()) {
		for (auto &c : SpriteList) {
			delete c;
		}
		SpriteList.clear();
	}
	for (auto &c : ScratchMain.Stage.Sprite) {
		SpriteListItem *Item = new SpriteListItem(c, this);
		SpriteList.push_back(Item);
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
	TextSprite->setText(AppTranslator["spritearea_sprite_topbar_sprites"]);
	TextSprite->move(10, 5);
	//TextSprite->adjustSize();

	ButtonNewSprite = new QPushButton(this);
	ButtonNewSprite->setObjectName("SpriteArea_SpriteArea_TopBar_ButtonNewSprite");
	ButtonNewSprite->move(370, 5);
	ButtonNewSprite->resize(20, 20);
	connect(ButtonNewSprite, SIGNAL(clicked()), this, SLOT(NewSprite()));

	TextNewSprite = new QLabel(this);
	TextNewSprite->setObjectName("SpriteArea_SpriteArea_TopBar_TextNewSprite");
	TextNewSprite->setText(AppTranslator["spritearea_sprite_topbar_newsprite"]);
	TextNewSprite->adjustSize();
	TextNewSprite->move(380 - ButtonNewSprite->width() - TextNewSprite->width(), 5);
}

SpriteArea_SpriteArea_TopBar::~SpriteArea_SpriteArea_TopBar() {
	delete this->TextSprite;
	delete this->ButtonNewSprite;
	delete this->TextNewSprite;
}

void SpriteArea_SpriteArea_TopBar::reloadTranslation() {
	this->TextSprite->setText(AppTranslator["spritearea_sprite_topbar_sprites"]);
	this->TextNewSprite->setText(AppTranslator["spritearea_sprite_topbar_newsprite"]);

	TextSprite->adjustSize();
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

void SpriteArea_SpriteArea_TopBar::NewSprite() {
	ScratchMain.Stage.CreateNewSprite();
	AppLogger.AddLog("Runtime", "Create sprite: ", ScratchMain.Stage.Sprite.at(ScratchMain.Stage.Sprite.size() - 1)->Name);
	SpriteListItem *Item = new SpriteListItem(ScratchMain.Stage.Sprite.at(ScratchMain.Stage.Sprite.size() - 1), dynamic_cast<Widget*>(parent()));
	dynamic_cast<SpriteArea_SpriteArea*>(parent())->SpriteList.push_back(Item);
	SpriteItem *Sprite = new SpriteItem(ScratchMain.Stage.Sprite.at(ScratchMain.Stage.Sprite.size() - 1), dynamic_cast<Widget*>(AppWindow->StageArea->StageView));
	ScratchMain.Stage.Sprite.at(ScratchMain.Stage.Sprite.size() - 1)->Item = Sprite;
	AppWindow->StageArea->StageView->Sprites.push_back(Sprite);
	Sprite->show();
	dynamic_cast<SpriteArea_SpriteArea*>(parent())->RefreshList();
}


