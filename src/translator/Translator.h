#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <map>

class Translator {
private:
	std::string UsingLanguage;
public:
	Translator();
	void LoadTranslation(std::string Path);
	void SetLanguage(std::string Lang);
	void SetLanguage();
	std::string operator[](std::string LocalisedString);
	//const char *operator[](const char *LocalisedString);
public:
	std::map<std::string, std::map<std::string, std::string>> TranslationString;
	std::map<std::string, std::string> LanguageMap;
};

extern Translator AppTranslator;

#endif // TRANSLATOR_H
