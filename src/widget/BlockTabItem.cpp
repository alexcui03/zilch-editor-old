#include "BlockTabItem.h"
#include "ScriptPart.h"

BlockTabItem::BlockTabItem(ScratchBlockCategory *CategoryData, QWidget *parent):Widget(parent) {
	this->CategoryData = CategoryData;
	this->Selected = false;
	setObjectName("EditArea_ScriptPart_BlockTabItem");
	resize(85, 20);

	Color = new QLabel(this);
	Color->setObjectName("EditArea_ScriptPart_BlockTab_LabelColor");
	Color->setAutoFillBackground(true);
	Color->move(0, 0);
	Color->resize(7, this->height());

	Text = new QLabel(this);
	Text->setObjectName("EditArea_ScriptPart_BlockTab_LabelText");
	Text->move(10, 0);
	Text->resize(this->width() - 10, this->height());

	connect(this, SIGNAL(leftclicked()), SLOT(OnSelect()));
	//connect(this, SIGNAL(onmouseenter()), SLOT(OnMouseEnter()));
	//connect(this, SIGNAL(onmouseleave()), SLOT(OnMouseLeave()));
}

void BlockTabItem::OnSelect() {
	auto BlockTab = dynamic_cast<ScriptPart_BlockTab*>(parentWidget());
	emit BlockTab->reloadview(CategoryData);
	Selected = true;
	if (BlockTab->LastClicked != nullptr) {
		BlockTab->LastClicked->Color->resize(7, BlockTab->LastClicked->height());
		BlockTab->LastClicked->Selected = false;
	}
	BlockTab->LastClicked = this;
	this->Color->resize(this->width(), this->height());
	Text->setPalette(QPalette(QColor(0xFFFFFF)));
	Text->update();
}
/*
void BlockTabItem::OnMouseEnter() {

}

void BlockTabItem::OnMouseLeave() {

}
*/
void BlockTabItem::setText(const QString &Text){
	this->Text->setText(Text);
}

void BlockTabItem::setPalette(const QPalette &Palette) {
	this->Color->setPalette(Palette);
}

