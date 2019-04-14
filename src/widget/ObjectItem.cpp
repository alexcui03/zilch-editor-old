#include "ObjectItem.h"

ObjectItem::ObjectItem(ScratchObject *object, QWidget *parent) : Widget(parent) {
	this->object = object;
}

ObjectItem::~ObjectItem() {

}

void ObjectItem::reload() {
	this->label->setPixmap(QPixmap::fromImage(*static_cast<QImage*>(this->object->CostumeList[this->object->CurrentCostume].resource->Data)));
}
