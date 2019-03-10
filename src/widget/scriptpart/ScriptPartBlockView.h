#ifndef SCRIPTPARTBLOCKVIEW_H
#define SCRIPTPARTBLOCKVIEW_H

#include "../Widget.h"
#include "../BlockItem.h"
#include "../../scratch/ScratchBlockCategory.h"

class ScriptPartBlockView : public Widget {
	Q_OBJECT
public:
	ScriptPartBlockView(QWidget *parent = nullptr);
	~ScriptPartBlockView();
public slots:
	void Reload(ScratchBlockCategory *Category);
public:
	std::vector<BlockItem*> Block;
};

#endif // SCRIPTPARTBLOCKVIEW_H
