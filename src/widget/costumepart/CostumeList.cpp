#include "CostumeList.h"

#include "../MainWindow.h"

/**
 * Constructor.
 * parent - The parent widget pointer.
 */
CostumeList::CostumeList(QWidget *parent) : Widget(parent) {

}

/**
 * Destructor.
 */
CostumeList::~CostumeList() {

}

/**
 * Reload the list when the select object changes.
 * This function will be called by EditArea::ChangeObject.
 */
void CostumeList::reload() {
	// Delete and free list items
	for (auto &c : this->list_items) {
		delete c;
	}
	this->list_items.clear();
	// Load costumes in new object
	// Design(CostumeList):
	//   padding: 5px 0px
	// Design(CostumeListItem):
	//   width: 80px
	//   height: 80px
	//   margin: 5px 10px
	int i = 0;
	for (auto &c : AppWindow->EditArea->Object->CostumeList) {
		CostumeListItem *item = new CostumeListItem(&c, this);
		item->move(10, 10 + 100 * i++);
		item->resize(80, 80);
		item->show();
		this->list_items.push_back(item);
	}
	CostumeListItem::selected_item = nullptr;
}
