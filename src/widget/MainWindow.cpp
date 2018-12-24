#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <fstream>
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

	MenuFile = new QMenu(AppTranslator["window_menubar_file"].c_str());
	MenuFile->setObjectName("Menu_File");
	MenuFile->addAction(AppTranslator["window_menubar_file_openfile"].c_str());
	MenuFile->addSeparator();
	MenuFile->addAction(AppTranslator["window_menubar_file_save"].c_str());
	MenuFile->addAction(AppTranslator["window_menubar_file_saveas"].c_str());
	MenuFile->addSeparator();
	MenuFile->addAction(AppTranslator["window_menubar_file_exit"].c_str());

	MenuOption = new QMenu(AppTranslator["window_menubar_option"].c_str());
	MenuOption->setObjectName("Menu_Option");
	MenuOption->addAction(AppTranslator["window_menubar_option_settings"].c_str());

	MenuBar->addMenu(MenuFile);
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
