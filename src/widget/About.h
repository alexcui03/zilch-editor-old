#ifndef ABOUT_H
#define ABOUT_H

#include <QLabel>

#include "Widget.h"

class About : public Widget {
public:
	About(QWidget *parent = nullptr);
	~About();
public:
	QLabel *logo;
	QLabel *txt;
};

#endif // ABOUT_H
