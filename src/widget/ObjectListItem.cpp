#include "ObjectListItem.h"

#include <QStyle>

#include "MainWindow.h"

ObjectListItem *ObjectListItem::selected_item = nullptr;

ObjectListItem::ObjectListItem(ScratchObject *object, QWidget *parent) : Widget(parent) {
	this->object = object;
	this->is_selected = false;
	this->setObjectName("ObjectListItem");

	this->text = new QLabel(this);
	this->text->setObjectName("ObjectListItem_Text");
	this->text->setText(this->object->Name.c_str());
	this->text->setAlignment(Qt::AlignCenter);

	connect(this, SIGNAL(leftclicked()), SLOT(select()));
}

ObjectListItem::~ObjectListItem() {

}

void ObjectListItem::select() {
	if (this->is_selected) {
		return;
	}
	if (ObjectListItem::selected_item != nullptr) {
		ObjectListItem::selected_item->is_selected = false;
		ObjectListItem::selected_item->setObjectName("ObjectListItem");
		ObjectListItem::selected_item->style()->unpolish(ObjectListItem::selected_item);
		ObjectListItem::selected_item->style()->polish(ObjectListItem::selected_item);
	}
	ObjectListItem::selected_item = this;
	this->is_selected = true;
	this->setObjectName("ObjectListItem-Select");
	this->style()->unpolish(this);
	this->style()->polish(this);
	AppWindow->EditArea->ChangeObject(this->object);
}
