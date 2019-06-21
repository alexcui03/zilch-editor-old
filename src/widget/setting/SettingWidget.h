#ifndef SETTING_WIDGET
#define SETTING_WIDGET

#include <QWidget>
#include <QTabWidget>

#include "SettingStyle.h"
#include "../Widget.h"

class SettingWidget : public Widget {
public:
	SettingWidget(QWidget *parent = nullptr);
	~SettingWidget();
public:
	QTabWidget tab_widget;
	SettingStyle setting_style;
};

#endif
