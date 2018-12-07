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
/*
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
			std::string FileName = Temp.path().filename().string();
			FileName = FileName.substr(0, FileName.find('.'));
			char *Buffer = new char[BUFSIZE];
			std::string String;
			while (!File.eof()) {
				File.getline(Buffer, BUFSIZE);
				String = Buffer;
				auto Index = String.find('=');
				TranslationString[FileName][String.substr(0, Index)] = String.substr(Index + 1);
			}
			File.close();
		}
	}
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
