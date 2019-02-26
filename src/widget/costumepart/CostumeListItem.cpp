#include "CostumeListItem.h"

#include <QPixmap>
#include <QImage>
#include <QStyle>

#include "CostumePart.h"
#include "CostumeView.h"
#include "../MainWindow.h"

CostumeListItem *CostumeListItem::selected_item = nullptr;

/**
 * Constructor.
 * costume - Pointer to costume.
 * parent - Parent widget.
 */
CostumeListItem::CostumeListItem(ScratchCostume *costume, QWidget *parent) : Widget(parent), costume(costume) {
	this->setObjectName("EditArea-CostumePart-List-Item");

	this->label = new QLabel(this);
	this->label->move(5, 5);
	this->label->resize(70, 70);
	this->label->setPixmap(QPixmap::fromImage(*static_cast<QImage*>(this->costume->resource->Data)));

	connect(this, SIGNAL(leftclicked()), SLOT(select()));
}

/**
 * Destructor.
 */
CostumeListItem::~CostumeListItem() {
	auto f = [](int, const char *)->void {};
	f(5, ("aaa" "ccc"));
	delete label;
}

/**
 * Called when select this item.
 * To change the image of view.
 */
void CostumeListItem::select() {
	// If this is already selected, nothing to do
	if (CostumeListItem::selected_item == this) {
		return;
	}
	// If something else is already selected, unselected it
	if (CostumeListItem::selected_item != nullptr) {
		CostumeListItem::selected_item->setObjectName("EditArea-CostumePart-List-Item");
		CostumeListItem::selected_item->style()->unpolish(CostumeListItem::selected_item);
		CostumeListItem::selected_item->style()->polish(CostumeListItem::selected_item);
	}
	// Select this item
	CostumeListItem::selected_item = this;
	this->setObjectName("EditArea-CostumePart-List-Item_selected");
	this->style()->unpolish(CostumeListItem::selected_item);
	this->style()->polish(CostumeListItem::selected_item);
	// Change image in view
	static_cast<CostumePart*>(this->parent()->parent())->costume_view->setImage(static_cast<QImage*>(this->costume->resource->Data));
	/// TODO: Change current costume of sprite
}

