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
#include "../logger/Logger.h"

/**
 * Constructor.
 * Block - Scratch block.
 * LastBlock - Last block.
 * NextBlock - Next block.
 * parent - Parent widget.
 */
BlockItem::BlockItem(ScratchBlock *Block, ScratchBlock *LastBlock, ScratchBlock *NextBlock, QWidget *parent):Widget(parent) {
	this->BlockData = Block;
	this->BlockData->LastBlock = LastBlock;
	this->BlockData->NextBlock = NextBlock;
	this->isDragging = false;
	this->isViewingBlock = false;
	this->needAdd = true;
	this->FillColor = BlockData->Block->Category->Color;
	this->FrameColor = QColor(BlockData->Block->Category->Color) * 0.9;
	this->ViewerIndex = 0;

	this->setObjectName("BlockItem");
	this->move(this->BlockData->X, this->BlockData->Y);

	TextLabel = new QLabel(this);
	TextLabel->setText(BlockData->Block->Name.c_str());
	TextLabel->setAlignment(Qt::AlignLeft);
	TextLabel->move(5, 3);
	TextLabel->adjustSize();


	switch(this->BlockData->Block->Type) {
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
}

void BlockItem::paintEvent(QPaintEvent *) {
	QPainter Painter(this);
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
		// If the block is in view.
		if (isViewingBlock) {
			// Copy a new block for viewing, and make current block for edit.
			BlockItem *NewItem = new BlockItem(this->BlockData, nullptr, nullptr, parentWidget());
			dynamic_cast<ScriptPartView*>(parentWidget())->Block[ViewerIndex] = NewItem;
			NewItem->isViewingBlock = true;
			NewItem->move(pos());
			NewItem->show();
			BlockData->Item = this;
			isViewingBlock = false;
			setParent(AppWindow);
			MovVector = e->pos();
			move(AppWindow->mapFromGlobal(e->globalPos()) - MovVector);
			show();
			isDragging = true;
			//this->BlockData->Object->BlockList.push_back(this->BlockData);
		}
		else {
			if (isDragging) {
				move(AppWindow->mapFromGlobal(e->globalPos()) - MovVector);
				ScratchBlock *LastTemp = this->BlockData;
				for (ScratchBlock *Temp = BlockData->NextBlock; Temp != nullptr; LastTemp = Temp, Temp = Temp->NextBlock) {
					Temp->Item->move(LastTemp->Item->x(), LastTemp->Item->y() + LastTemp->Item->height() - 3);
				}
			}
			else {
				// First time move.
				if (BlockData->LastBlock != nullptr) {
					BlockData->LastBlock->NextBlock = nullptr;
					BlockData->LastBlock = nullptr;
				}
				MovVector = e->pos();
				setParent(AppWindow);
				move(AppWindow->mapFromGlobal(e->globalPos()) - MovVector);
				show();
				ScratchBlock *LastTemp = this->BlockData;
				for (ScratchBlock *Temp = BlockData->NextBlock; Temp != nullptr; LastTemp = Temp, Temp = Temp->NextBlock) {
					Temp->Item->setParent(AppWindow);
					Temp->Item->move(LastTemp->Item->x(), LastTemp->Item->y() + LastTemp->Item->height() - 3);
					Temp->Item->show();
				}
				isDragging = true;
			}
		}
	}
}

void BlockItem::mouseReleaseEvent(QMouseEvent *e) {
	static auto Edit = AppWindow->EditArea->ScriptPart->ScriptEdit;
	if (e->button() == Qt::LeftButton) {
		// If the block is on dragging and for edit.
		if (this->isDragging) {
			// If the block is not in edit area.
			if (!Edit->rect().contains(Edit->mapFromGlobal(e->globalPos()))) {
				// Delete all block below.
				ScratchBlock *LastTemp = this->BlockData;
				for (ScratchBlock *Temp = this->BlockData->NextBlock; Temp != nullptr; LastTemp = Temp, Temp = Temp->NextBlock) {
					delete LastTemp;
				}
			}
			else {
				// Search for the nearest block that can be connect to.
				BlockItem *Nearest = nullptr;
				if (this->BlockData->Block->Type == ScratchBlockType::BODY_BLOCK)
					Nearest = SearchNearest(Edit->mapFromGlobal(e->globalPos()) - MovVector);
				// End dragging.
				this->isDragging = false;
				this->setParent(Edit);
				if (Nearest != nullptr) {
					// Insert as next for the nearest block.
					this->BlockData->NextBlock = Nearest->BlockData->NextBlock;
					Nearest->BlockData->NextBlock = this->BlockData;
					this->BlockData->LastBlock = Nearest->BlockData;
					move(Nearest->pos().x(), Nearest->pos().y() + Nearest->height() - 4);
				}
				else {
					// No search for the nearest block.
					move(Edit->mapFromGlobal(e->globalPos()) - MovVector);
					//this->BlockData->Object = AppWindow->EditArea->Object;
					this->BlockData->X = this->x();
					this->BlockData->Y = this->y();
					if (this->needAdd) {
						AppWindow->EditArea->Object->BlockList.push_back(this->BlockData);
						this->needAdd = false;
					}
				}
				this->show();
				// Move all blocks below.
				ScratchBlock *LastTemp = this->BlockData;
				for (ScratchBlock *Temp = this->BlockData->NextBlock; Temp != nullptr; LastTemp = Temp, Temp = Temp->NextBlock) {
					Temp->Item->setParent(Edit);
					Temp->Item->move(LastTemp->Item->x(), LastTemp->Item->y() + LastTemp->Item->height() - 4);
					Temp->Item->show();
				}
			}
		}
	}
}

BlockItem *BlockItem::SearchNearest(const QPoint &Pos) const {
	auto &BlockList = AppWindow->EditArea->ScriptPart->ScriptEdit->children();
	// If there is no block in block list than return.
	if (BlockList.empty()) {
		return nullptr;
	}
	QWidget *Nearest = nullptr;
	// The max distance between current block and nearest block.
	int DistanceX = 15;
	int DistanceY = 15;
	for (const auto &c : BlockList) {
		if (std::abs(Pos.y() - (dynamic_cast<QWidget*>(c)->y() + dynamic_cast<QWidget*>(c)->height())) < DistanceY &&
			std::abs(Pos.x() - dynamic_cast<QWidget*>(c)->x()) < DistanceX) {
			DistanceX = std::abs(Pos.y() - (dynamic_cast<QWidget*>(c)->y() + dynamic_cast<QWidget*>(c)->height()));
			DistanceY = std::abs(Pos.x() - dynamic_cast<QWidget*>(c)->x());
			Nearest = dynamic_cast<QWidget*>(c);
		}
	}
	return dynamic_cast<BlockItem*>(Nearest);
}
