#ifndef SCRIPTPARTEDIT_H
#define SCRIPTPARTEDIT_H

#include "../Widget.h"

class ScriptPartEdit : public Widget {
	Q_OBJECT
public:
	ScriptPartEdit(QWidget *parent = nullptr);
	~ScriptPartEdit();
public slots:
	void Reload();
};

#endif // SCRIPTPARTEDIT_H
