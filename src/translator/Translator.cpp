#include "Translator.h"
#include "../logger/Logger.h"
#include <filesystem>
#include <fstream>
#include <QDebug>

namespace fs = std::experimental::filesystem;

constexpr unsigned int BUFSIZE = 1024;

Translator::Translator() {

}

std::string Translator::operator[](std::string LocalisedString) {
	auto &StringMap = TranslationString[UsingLanguage];
	if (StringMap.find(LocalisedString) == StringMap.end()) {
		AppLogger.AddWarning("Translator", "Translation string of " + LocalisedString + " does not exist in " + UsingLanguage + ".");
		return LocalisedString;
	}
	else {
		return StringMap[LocalisedString];
	}
}
/* for const char*
const char *Translator::operator[](const char *LocalisedString) {
	auto &StringMap = TranslationString[UsingLanguage];
	if (StringMap.find(LocalisedString) == StringMap.end()) {
		AppLogger.AddWarning("Translator", "Translation string of " + std::string(LocalisedString) + " does not exist in " + UsingLanguage + ".");
		return LocalisedString;
	}
	else {
		return StringMap[LocalisedString].c_str();
	}
}
*/
void Translator::LoadTranslation(std::string Path) {
	for (const auto &Temp : fs::directory_iterator(Path)) {
		if (fs::is_directory(Temp)) {
			LoadTranslation(Temp.path().string());
		}
		else {
			AppLogger.AddSplashLog("Translator", "Loading translation: " + Temp.path().string());
			std::ifstream File(Temp);
			std::string CurruentLanguage = "en";
			char *Buffer = new char[BUFSIZE];
			std::string String;
			while (!File.eof()) {
				File.getline(Buffer, BUFSIZE);
				String = Buffer;
				if (String.empty() || String[0] == '#') { // No word in string.
					continue;
				}

				String.erase(0, String.find_first_not_of(" ")); // Delete space before word.
				String.erase(String.find_last_not_of(" ") + 1); // Delete space after word.
				if (String.empty()) { // No word in string.
					continue;
				}

				auto Index = String.find(':');
				if (Index == std::string::npos) { // No found for ':'.
					continue;
				}

				auto Key = String.substr(0, Index);
				Key.erase(Key.find_last_not_of(" ") + 1); // Delete space after word.
				auto Word = String.substr(Index + 1);
				Word.erase(0, Word.find_first_not_of(" ")); // Delete space before word.

				if (Key == "current_lang") {
					CurruentLanguage = Word;
				}
				else {
					if (CurruentLanguage == "lang") {
						Key = Key.substr(5);
						LanguageMap[Key] = Word; // Add language type.
					}
					else {
						TranslationString[CurruentLanguage][Key] = Word; // Add translation to map.
					}
				}
			}
			File.close();
		}
	}
	/* Output languages
	AppLogger.AddLog("Debug", "Language List");
	for (auto &c : LanguageMap) {
		AppLogger.AddLog("Debug", c.first + ":" + c.second);
	}
	AppLogger.AddLog("Debug", "Key List");
	for (auto &c : TranslationString) {
		AppLogger.AddLog("Debug", c.first);
		for (auto &d : c.second) {
			AppLogger.AddLog("Debug", "  " + d.first + ":" + d.second);
		}
	}
	*/
}

void Translator::SetLanguage(std::string Lang) {
	UsingLanguage = Lang;
}

void Translator::SetLanguage() {
	if (TranslationString.find("en") == TranslationString.end()) {
		UsingLanguage = TranslationString.begin()->first;
	}
	else {
		UsingLanguage = "en";
	}
}
