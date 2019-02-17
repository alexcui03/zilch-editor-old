#ifndef COSTUMENEW_H
#define COSTUMENEW_H

#include <QPushButton>

#include "../Widget.h"

class CostumeNew : public Widget {
public:
	explicit CostumeNew(QWidget *parent = nullptr);
	~CostumeNew();
public:
	QPushButton from_file;
};

#endif // COSTUMENEW_H
