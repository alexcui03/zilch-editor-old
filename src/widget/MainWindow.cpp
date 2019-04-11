#include "MainWindow.h"

#include <fstream>

#include <QMenuBar>
#include <QMenu>
#include <QApplication>

#include "About.h"
#include "LanguageAction.h"
#include "../translator/Translator.h"

std::vector<std::string> GetTitleList() {
	std::vector<std::string> title;
	std::ifstream fin("./config/title.list");
	if (!fin.is_open()) {
		return title;
	}
	char *buffer = new char[1024];
	while (!fin.eof()) {
		fin.getline(buffer, 1024);
		title.push_back(buffer);
	}
	return title;
}

MainWindow::MainWindow(std::string Title, QWidget *parent):QMainWindow(parent) {
	setObjectName("MainWindow");
	setWindowTitle(Title.c_str());
	resize(800, 600);

	MenuBar = this->menuBar();
	MenuBar->resize(this->width(), 30);
	MenuBar->setObjectName("Menu");

	MenuFile = new QMenu(AppTranslator["window_menubar_file"]);
	MenuFile->setObjectName("Menu_File");
	MenuFile->addAction(AppTranslator["window_menubar_file_openfile"]);
	MenuFile->addSeparator();
	MenuFile->addAction(AppTranslator["window_menubar_file_save"]);
	MenuFile->addAction(AppTranslator["window_menubar_file_saveas"]);
	MenuFile->addSeparator();
	MenuFile->addAction(AppTranslator["window_menubar_file_exit"]);

	MenuLang = new QMenu(AppTranslator["window_menubar_lang"]);
	MenuLang->setObjectName("Menu_Lang");
	for (const auto &c : AppTranslator.LanguageMap) {
		new LanguageAction(c.second, c.first, static_cast<void(QObject::*)(std::string)>(&MainWindow::setLanguage), MenuLang);
	}

	MenuOption = new QMenu(AppTranslator["window_menubar_option"]);
	MenuOption->setObjectName("Menu_Option");
	MenuOption->addAction(AppTranslator["window_menubar_option_settings"]);
	MenuOption->addAction(AppTranslator["window_menubar_option_about_qt"], qApp, SLOT(aboutQt()));
	MenuOption->addAction(AppTranslator["window_menubar_option_about_ze"], this, SLOT(about()));

	MenuBar->addMenu(MenuFile);
	MenuBar->addMenu(MenuLang);
	MenuBar->addMenu(MenuOption);

	StageArea = new ::StageArea(this);
	StageArea->setObjectName("StageArea");
	StageArea->move(10, 40);
	StageArea->resize(480, 410);

	SpriteArea = new ::SpriteArea(this);
	SpriteArea->setObjectName("SpriteArea");
	SpriteArea->move(10, 460);
	SpriteArea->resize(480, this->size().height() - 470);

	EditArea = new ::EditArea(this);
	EditArea->setObjectName("EditArea");
	EditArea->move(500, 40);
	EditArea->resize(this->size().width() - 510, this->size().height() - 50);

	showMaximized();
}

MainWindow::~MainWindow() {

}

void MainWindow::resizeEvent(QResizeEvent* size) {
	SpriteArea->resize(480, size->size().height() - 470);
	EditArea->resize(this->size().width() - 510, this->size().height() - 50);
}

void MainWindow::about() {
	About *about = new About();
	about->show();
}

void MainWindow::setLanguage(std::string lang) {
	AppTranslator.SetLanguage(lang);
}

void MainWindow::reloadTranslation() {
	this->MenuFile->setTitle(AppTranslator["window_menubar_file"]);
	this->MenuLang->setTitle(AppTranslator["window_menubar_lang"]);
	this->MenuOption->setTitle(AppTranslator["window_menubar_option"]);

	this->StageArea->reloadTranslation();
	this->SpriteArea->reloadTranslation();
	this->EditArea->reloadTranslation();
}

