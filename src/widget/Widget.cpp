#include "Widget.h"
#include <QStyleOption>
#include <QPainter>

Widget::Widget(QWidget *parent):QWidget(parent) {
	LeftPressed = false;
	RightPressed = false;

	connect(this, SIGNAL(leftclicked()), SLOT(DefMouseProc()));
	connect(this, SIGNAL(rightclicked()), SLOT(DefMouseProc()));
	connect(this, SIGNAL(onmouseenter()), SLOT(DefMouseProc()));
	connect(this, SIGNAL(onmouseleave()), SLOT(DefMouseProc()));
}

Widget::~Widget() {

}

void Widget::reloadTranslation() {
	return;
}

void Widget::paintEvent(QPaintEvent *) {
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Widget::mousePressEvent(QMouseEvent *e) {
	if (e->button() == Qt::LeftButton) {
		LeftPressed = true;
	}
	else {
		RightPressed = true;
	}
}

void Widget::mouseReleaseEvent(QMouseEvent *e) {
	if (e->button() == Qt::LeftButton) {
		if (LeftPressed) {
			emit leftclicked();
			LeftPressed = false;
		}
	}
	else {
		if (RightPressed) {
			emit rightclicked();
			RightPressed = false;
		}
	}
}

void Widget::enterEvent(QEvent *) {
	emit onmouseenter();
}

void Widget::leaveEvent(QEvent *) {
	emit onmouseleave();
}

void Widget::mouseMoveEvent(QMouseEvent *) {
	return;
}

void Widget::DefMouseProc() {
	return;
}

