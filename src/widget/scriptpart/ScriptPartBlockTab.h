#ifndef SCRIPTPARTBLOCKTAB_H
#define SCRIPTPARTBLOCKTAB_H

#include "BlockTabItem.h"
#include "../Widget.h"
#include "../../scratch/ScratchBlockCategory.h"

class ScriptPartBlockTab : public Widget {
	Q_OBJECT
public:
	ScriptPartBlockTab(QWidget *parent = nullptr);
	~ScriptPartBlockTab() override;
	virtual void reloadTranslation() override;
public slots:
	void Reload();
signals:
	void reloadview(ScratchBlockCategory*);
public:
	BlockTabItem *LastClicked;
	std::vector<BlockTabItem*> BlockTab;
};

#endif // SCRIPTPARTBLOCKTAB_H
