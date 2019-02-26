#include "CostumeView.h"

#include <QPixmap>

/**
 * Constructor.
 * parent - The parent widget pointer.
 */
CostumeView::CostumeView(QWidget *parent) : Widget(parent) {
	this->view = new QLabel(this);
	this->view->move(0, 0);
}

/**
 * Called when the widget size changes.
 */
void CostumeView::resizeEvent(QResizeEvent *) {
	this->view->resize(this->width(), this->height());
}

/**
 * Destructor.
 */
CostumeView::~CostumeView() {
	delete view;
}

/**
 * Set the image of the label.
 * image - The pointer to image.
 */
void CostumeView::setImage(QImage *image) {
	this->view->setPixmap(QPixmap::fromImage(*image));
}
