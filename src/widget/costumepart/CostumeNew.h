#ifndef COSTUMENEW_H
#define COSTUMENEW_H

#include <QPushButton>
#include <QLabel>

#include "../Widget.h"

class CostumeNew : public Widget {
	Q_OBJECT
public:
	explicit CostumeNew(QWidget *parent = nullptr);
	~CostumeNew();
public slots:
	void importFromFile();
public:
	QLabel *txt_new_sprite;
	QPushButton *btn_from_file;
};

#endif // COSTUMENEW_H
