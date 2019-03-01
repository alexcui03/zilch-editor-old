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
	~MainWindow();
	//bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	void resizeEvent(QResizeEvent* size);
public slots:
	void about();
public:
	QMenuBar *MenuBar;
	QMenu *MenuFile;
	QMenu *MenuOption;
	StageArea *StageArea;
	SpriteArea *SpriteArea;
	EditArea *EditArea;
};

extern MainWindow *AppWindow;

#endif // MAINWINDOW_H
