#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <string>

#include <QMainWindow>
#include <QWidget>
#include <QResizeEvent>

#include "StageArea.h"
#include "SpriteArea.h"
#include "EditArea.h"

std::vector<std::string> GetTitleList();

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
	explicit MainWindow(std::string TitleList, QWidget *parent = nullptr);
	~MainWindow() override;
	void resizeEvent(QResizeEvent* size) override;
	void reloadTranslation();
public slots:
	void about();
	void setLanguage(std::string lang);
public:
	QMenuBar *MenuBar;
	QMenu *MenuFile;
	QMenu *MenuOption;
	QMenu *MenuLang;
	StageArea *StageArea;
	SpriteArea *SpriteArea;
	EditArea *EditArea;
};

extern MainWindow *AppWindow;

#endif // MAINWINDOW_H
