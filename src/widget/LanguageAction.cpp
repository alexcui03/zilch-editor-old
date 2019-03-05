#include "LanguageAction.h"

#include "MainWindow.h"

LanguageAction::LanguageAction(std::string title, std::string lang, LanguageActionFunction function, QMenu *menu) : QAction(title.c_str()) {
	this->lang = lang;
	this->function = function;
	menu->addAction(this);

	connect(this, SIGNAL(triggered()), SLOT(onTriggered()));
}

LanguageAction::~LanguageAction() {

}

void LanguageAction::onTriggered() {
	(AppWindow->*this->function)(this->lang);
}

