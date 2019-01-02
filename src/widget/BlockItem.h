#ifndef BLOCKITEM_H
#define BLOCKITEM_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include "Widget.h"
#include "../scratch/ScratchBlock.h"
#include "../scratch/ScratchObject.h"

class BlockItem : public Widget {
	Q_OBJECT
public:
	BlockItem(ScratchBlock *Block, ScratchBlock *LastBlock, ScratchBlock *NextBlock, QWidget *parent = nullptr);
	BlockItem *SearchNearest(const QPoint &Pos) const;
public slots:
	void paintEvent(QPaintEvent *e) override;
	void mousePressEvent(QMouseEvent *e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;
public:
	bool isViewingBlock;
	ScratchBlock *BlockData;
	size_t ViewerIndex;
	QLabel *TextLabel;
private:
	bool isDragging;
	QPoint StartPos;
	QPoint MovVector;
	QPolygonF Polygon;
	QColor FillColor;
	QColor FrameColor;
};

#endif // BLOCKITEM_H
