#include "SettingWidget.h"

#include "../../translator/Translator.h"

SettingWidget::SettingWidget(QWidget *parent) : Widget(parent) {
	this->tab_widget.setTabPosition(QTabWidget::West);
	this->tab_widget.addTab(&setting_style, AppTranslator["setting_style"]);
}

SettingWidget::~SettingWidget() {

}
