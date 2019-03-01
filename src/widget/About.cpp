#include "About.h"

#include <QPixmap>
#include <QImage>

About::About(QWidget *parent) : Widget(parent) {
	this->logo = new QLabel(this);
	this->logo->setPixmap(QPixmap::fromImage(QImage("./asset/splash.png")));
	this->logo->move(20, 20);
	this->logo->adjustSize();

	this->txt = new QLabel(this);
	this->txt->setText(
		"\n"
		"Zilch Editor\n"
		"Copyright (c) 2018-2019 Alex Cui\n"
		"\n"
		"This program is free software: you can redistribute it and/or modify\n"
		"it under the terms of the GNU General Public License as published by\n"
		"the Free Software Foundation, either version 3 of the License, or\n"
		"(at your option) any later version.\n"
		"\n"
		"This program is distributed in the hope that it will be useful,\n"
		"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
		"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
		"GNU General Public License for more details.\n"
		"\n"
		"You should have received a copy of the GNU General Public License\n"
		"along with this program.  If not, see <https://www.gnu.org/licenses/>.\n"
		"\n"
	);
	this->txt->move(20, this->logo->height() + 40);
	this->txt->adjustSize();

	this->resize(this->logo->width() + 40, this->txt->height() + this->logo->height() + 60);
}

About::~About() {
	delete this->logo;
	delete this->txt;
}


