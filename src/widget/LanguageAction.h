#ifndef LANGUAGEACTION_H
#define LANGUAGEACTION_H

#include <string>

#include <QAction>
#include <QMenu>

using LanguageActionFunction = void(QObject::*)(std::string);

class LanguageAction : public QAction {
	Q_OBJECT
public:
	LanguageAction(std::string title, std::string lang, LanguageActionFunction function, QMenu *parent = nullptr);
	~LanguageAction();
public slots:
	void onTriggered();
public:
	std::string lang;
	LanguageActionFunction function;
};

#endif // LANGUAGEACTION_H
