#include "BlockItem.h"
#include <cmath>
#include <QApplication>
#include <QPalette>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QPolygonF>
#include <QPoint>
#include <QVector2D>
#include <QObjectList>
#include "MainWindow.h"
#include "ScriptPart.h"
#include "../scratch/ScratchBlockCategory.h"
#include "../util/Util.h"

BlockItem::BlockItem(ScratchBlock *Block, BlockItem *LastBlock, BlockItem *NextBlock, QWidget *parent):Widget(parent) {
	this->BlockData = Block;
	this->LastBlock = LastBlock;
	this->NextBlock = NextBlock;
	this->isDragging = false;
	this->isViewingBlock = false;
	this->FillColor = BlockData->Category->Color;
	this->FrameColor = QColor(BlockData->Category->Color) * 0.9;
	this->ViewerIndex = 0;

	setObjectName("BlockItem");

	TextLabel = new QLabel(this);
	TextLabel->setText(BlockData->Name.c_str());
	TextLabel->setAlignment(Qt::AlignLeft);
	TextLabel->move(5, 3);
	TextLabel->adjustSize();


	switch(this->BlockData->Type) {
	case ScratchBlockType::HEAD_BLOCK: {
		TextLabel->move(5, 13);
		adjustSize();
		resize((width() + 3 > 50) ? (width() + 3) : 50 , height() - 5);
		Polygon.append(QPointF(0, 13));
		Polygon.append(QPointF(13, 0));
		Polygon.append(QPointF(33, 0));
		Polygon.append(QPointF(43, 10));
		Polygon.append(QPointF(rect().right() - 3, 10));
		Polygon.append(QPointF(rect().right(), 13));
		Polygon.append(QPointF(rect().right(), rect().bottom() - 6));
		Polygon.append(QPointF(rect().right() - 3, rect().bottom() - 3));
		Polygon.append(QPointF(29, rect().bottom() - 3));
		Polygon.append(QPointF(26, rect().bottom()));
		Polygon.append(QPointF(16, rect().bottom()));
		Polygon.append(QPointF(13, rect().bottom() - 3));
		Polygon.append(QPointF(3, rect().bottom() - 3));
		Polygon.append(QPointF(0, rect().bottom() - 6));
		Polygon.append(QPointF(0, 13));
		break;
	}
	case ScratchBlockType::BODY_BLOCK: {
		adjustSize();
		resize(width() + 3, height() + 5);
		Polygon.append(QPointF(0, 3));
		Polygon.append(QPointF(3, 0));
		Polygon.append(QPointF(13, 0));
		Polygon.append(QPointF(16, 3));
		Polygon.append(QPointF(26, 3));
		Polygon.append(QPointF(29, 0));
		Polygon.append(QPointF(rect().right() - 3, 0));
		Polygon.append(QPointF(rect().right(), 3));
		Polygon.append(QPointF(rect().right(), rect().bottom() - 6));
		Polygon.append(QPointF(rect().right() - 3, rect().bottom() - 3));
		Polygon.append(QPointF(29, rect().bottom() - 3));
		Polygon.append(QPointF(26, rect().bottom()));
		Polygon.append(QPointF(16, rect().bottom()));
		Polygon.append(QPointF(13, rect().bottom() - 3));
		Polygon.append(QPointF(3, rect().bottom() - 3));
		Polygon.append(QPointF(0, rect().bottom() - 6));
		Polygon.append(QPointF(0, 3));
		break;
	}
	case ScratchBlockType::TAIL_BLOCK: {
		adjustSize();
		resize(width() + 3, height() + 2);
		Polygon.append(QPointF(0, 3));
		Polygon.append(QPointF(3, 0));
		Polygon.append(QPointF(13, 0));
		Polygon.append(QPointF(16, 3));
		Polygon.append(QPointF(26, 3));
		Polygon.append(QPointF(29, 0));
		Polygon.append(QPointF(rect().right() - 3, 0));
		Polygon.append(QPointF(rect().right(), 3));
		Polygon.append(QPointF(rect().right(), rect().bottom() - 3));
		Polygon.append(QPointF(rect().right() - 3, rect().bottom()));
		Polygon.append(QPointF(3, rect().bottom()));
		Polygon.append(QPointF(0, rect().bottom() - 3));
		Polygon.append(QPointF(0, 3));
		break;
	}
	case ScratchBlockType::BOOL_BLOCK: {
		adjustSize();
		resize(width() + 3, height() + 5);
		break;
	}
	case ScratchBlockType::NUMB_BLOCK: {
		adjustSize();
		resize(width() + 3, height() + 5);
		break;
	}
	case ScratchBlockType::NULL_BLOCK: {
		adjustSize();
		resize(width() + 3, height() + 5);
		break;
	}
	}

	connect(this, SIGNAL(copy(const QPoint &)), SLOT(Copy(const QPoint &)));
	connect(this, SIGNAL(run()), SLOT(RunFunction()));
}

void BlockItem::RunFunction() {
	BlockData->Function();
	if (NextBlock != nullptr) {
		NextBlock->RunFunction();
	}
}

void BlockItem::paintEvent(QPaintEvent *) {
/*	QRect Rect = this->rect();
	QPixmap Pixmap(Rect.size());
	Pixmap.fill(this, Rect.topLeft());
	QPainter Painter(&Pixmap);
	Painter.setBrush(QBrush(FillColor));
	Painter.setPen(QPen(FrameColor));
	Painter.drawPolygon(Polygon);
	Painter.end();
	QPainter Device(this);
	Device.drawPixmap(Rect.topLeft(), Pixmap);
*/	QPainter Painter(this);
	Painter.setBrush(QBrush(FillColor));
	Painter.setPen(QPen(FrameColor));
	Painter.drawPolygon(Polygon);
}

void BlockItem::mousePressEvent(QMouseEvent *e) {
	if (e->button() == Qt::LeftButton) {
		//StartPos = e->globalPos();
	}
}

void BlockItem::mouseMoveEvent(QMouseEvent *e) {
	if (e->buttons() & Qt::LeftButton) {
		if (isViewingBlock) {
			BlockItem *NewItem = new BlockItem(this->BlockData, nullptr, nullptr, parentWidget());
			dynamic_cast<ScriptPart_BlockView*>(parentWidget())->Block[ViewerIndex] = NewItem;
			NewItem->isViewingBlock = true;
			NewItem->move(pos());
			NewItem->show();
			setParent(AppWindow);
			MovVector = e->pos();
			move(AppWindow->mapFromGlobal(e->globalPos()) - MovVector);
			show();
			isViewingBlock = false;
			isDragging = true;
		}
		else {
			if (isDragging) {
				move(AppWindow->mapFromGlobal(e->globalPos()) - MovVector);
				auto LastTemp = this;
				for (auto Temp = NextBlock; Temp != nullptr; LastTemp = Temp, Temp = Temp->NextBlock) {
					Temp->move(LastTemp->x(), LastTemp->y() + LastTemp->height() - 3);
				}
			}
			else {
				if (LastBlock != nullptr) {
					LastBlock->NextBlock = nullptr;
					LastBlock = nullptr;
				}
				MovVector = e->pos();
				move(AppWindow->mapFromGlobal(e->globalPos()) - MovVector);
				setParent(AppWindow);
				show();
				auto LastTemp = this;
				for (auto Temp = NextBlock; Temp != nullptr; LastTemp = Temp, Temp = Temp->NextBlock) {
					Temp->setParent(AppWindow);
					Temp->move(LastTemp->x(), LastTemp->y() + LastTemp->height() - 3);
					Temp->show();
				}
				isDragging = true;
			}
		}
	}
}

void BlockItem::mouseReleaseEvent(QMouseEvent *e) {
	static auto Edit = AppWindow->EditArea->ScriptPart->ScriptEdit;
	if (e->button() == Qt::LeftButton) {
		if (isDragging && !isViewingBlock) {
			if (!Edit->rect().contains(Edit->mapFromGlobal(e->globalPos()))) {
				delete this;
			}
			else {
				BlockItem *Nearest = SearchNearest(Edit->mapFromGlobal(e->globalPos()) - MovVector);
				isDragging = false;
				setParent(Edit);
				if (Nearest != nullptr) {
					Nearest->NextBlock = this;
					LastBlock = Nearest;
					move(Nearest->pos().x(), Nearest->pos().y() + Nearest->height() - 4);
				}
				else {
					move(Edit->mapFromGlobal(e->globalPos()) - MovVector);
				}
				show();
				auto TempLast = this;
				for (auto Temp = NextBlock; Temp != nullptr; TempLast = Temp, Temp = Temp->NextBlock) {
					Temp->setParent(Edit);
					Temp->move(TempLast->x(), TempLast->y() + TempLast->height() - 3);
					Temp->show();
				}
			}
		}
	}
}

BlockItem *BlockItem::SearchNearest(const QPoint &Pos) const {
	auto &BlockList = AppWindow->EditArea->ScriptPart->ScriptEdit->children();
	if (BlockList.empty()) {
		return nullptr;
	}
	QWidget *Nearest = nullptr;
	int DistanceX = 30;
	int DistanceY = 30;
	for (const auto &c : BlockList) {
		if (std::abs(Pos.y() - (dynamic_cast<QWidget*>(c)->y() + dynamic_cast<QWidget*>(c)->height())) < DistanceY &&
			std::abs(Pos.x() - dynamic_cast<QWidget*>(c)->x()) < DistanceX) {
			DistanceX = std::abs(Pos.y() - (dynamic_cast<QWidget*>(c)->y() + dynamic_cast<QWidget*>(c)->height()));
			DistanceY = std::abs(Pos.x() - dynamic_cast<QWidget*>(c)->x());
			Nearest = dynamic_cast<QWidget*>(c);
			break;
		}
	}
	return dynamic_cast<BlockItem*>(Nearest);
}

void BlockItem::Copy(const QPoint &Pos) {
	BlockItem *NewItem = new BlockItem(this->BlockData, nullptr, nullptr, AppWindow);
	NewItem->isViewingBlock = false;
	NewItem->isDragging = true;
	NewItem->MovVector = pos();
	NewItem->move(Pos);
	NewItem->show();
}
