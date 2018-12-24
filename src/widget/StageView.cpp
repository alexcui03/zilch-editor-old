#include "StageView.h"
#include <QStyleOption>
#include <QPainter>

StageView::StageView(QWidget *parent):Widget(parent) {
	TestSprite = new Widget(this);
	//TestSprite->move(ConvertXY(-5, 5));
	TestSprite->move(100, 100);
	TestSprite->resize(10, 10);
	TestSprite->setAutoFillBackground(true);
	TestSprite->setPalette(QPalette(QColor(0xFFB11B)));
}

QPoint StageView::ConvertXY(int x, int y) {
	return QPoint(Width / 2 + x, Height / 2 - y);
}


