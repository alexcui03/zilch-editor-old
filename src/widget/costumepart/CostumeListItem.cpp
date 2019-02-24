#include "CostumeListItem.h"

#include <QPixmap>
#include <QImage>

CostumeListItem::CostumeListItem(ScratchCostume *costume, QWidget *parent) : Widget(parent), costume(costume) {
	this->setObjectName("EditArea-CostumePart-List-Item");

	this->label = new QLabel(this);
	this->label->setPixmap(QPixmap::fromImage(*static_cast<QImage*>(this->costume->Resourse->Data)));
}

CostumeListItem::~CostumeListItem() {

}

