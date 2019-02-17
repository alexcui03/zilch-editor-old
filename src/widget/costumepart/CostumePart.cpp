#include "CostumePart.h"

CostumePart::CostumePart(QWidget *parent) : Widget(parent) {
	this->costume_new = new CostumeNew(this);
	this->costume_new->setObjectName("EditArea_CostumePart_New");
	this->costume_new->move(0, 0);
	this->costume_new->resize(100, 40);

	this->costume_list = new CostumeList(this);
	this->costume_list->setObjectName("EditArea_CostumePart_List");
	this->costume_list->move(0, 40);
	this->costume_list->resize(100, this->height() - 40);

	this->costume_view = new CostumeView(this);
	this->costume_view->setObjectName("EditArea_CostumePart_View");
	this->costume_view->move(105, 5);
	this->costume_view->resize(this->width() - 115, this->height() - 10);
}

CostumePart::~CostumePart() {

}

void CostumePart::resizeEvent(QResizeEvent* size) {
	this->costume_list->resize(100, size->size().height() - 40);
	this->costume_view->resize(size->size().width() - 55, size->size().height() - 10);
}
