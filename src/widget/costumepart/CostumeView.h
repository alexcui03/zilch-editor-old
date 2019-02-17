#ifndef COSTUMEVIEW_H
#define COSTUMEVIEW_H

#include <QLabel>

#include "../Widget.h"

class CostumeView : public Widget {
public:
	CostumeView(QWidget *parent = nullptr);
	~CostumeView();
public:
	QLabel view;
};

#endif // COSTUMEVIEW_H
