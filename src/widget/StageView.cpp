#include "StageView.h"
#include <QStyleOption>
#include <QPainter>

StageView::StageView(QWidget *parent):Widget(parent) {

}

QPoint StageView::ConvertXY(int x, int y) {
	return QPoint(Width / 2 + x, Height / 2 - y);
}


