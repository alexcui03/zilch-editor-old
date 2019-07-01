#include "SettingWidget.h"

#include "../../translator/Translator.h"

SettingWidget::SettingWidget(QWidget *parent) : Widget(parent) {
	this->tab_widget.setParent(this);
	this->tab_widget.setTabPosition(QTabWidget::West);
	this->tab_widget.move(0, 0);
	this->tab_widget.resize(this->width(), this->height() - 30);
	
	this->tab_widget.addTab(&setting_style, AppTranslator["setting_style"]);
}

SettingWidget::~SettingWidget() {

}
