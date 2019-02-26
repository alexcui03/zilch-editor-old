#ifndef COSTUMEVIEW_H
#define COSTUMEVIEW_H

#include <QLabel>
#include <QImage>

#include "../Widget.h"

class CostumeView : public Widget {
public:
	CostumeView(QWidget *parent = nullptr);
	~CostumeView();
	void resizeEvent(QResizeEvent *);
	void setImage(QImage *image);
public:
	QLabel *view;
};

#endif // COSTUMEVIEW_H
