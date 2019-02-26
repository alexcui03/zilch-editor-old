#include "CostumeNew.h"

#include <string>
#include <fstream>

#include <QFileDialog>
#include <QImage>

#include "../MainWindow.h"
#include "../../scratch/Scratch.h"
#include "../../scratch/ScratchResource.h"
#include "../../scratch/ScratchCostume.h"
#include "../../scratch/ScratchObject.h"

/**
 * Constructor.
 * parent - Parent widget.
 */
CostumeNew::CostumeNew(QWidget *parent) : Widget(parent) {
	this->txt_new_sprite = new QLabel(this);
	this->txt_new_sprite->setObjectName("EditArea_CostumePart_New_Label");
	this->txt_new_sprite->move(10, 10);
	this->txt_new_sprite->resize(50, 20);
	this->txt_new_sprite->setText("Import:");

	this->btn_from_file = new QPushButton(this);
	this->btn_from_file->setObjectName("EditArea_CostumePart_New_BtnFromFile");
	this->btn_from_file->move(70, 10);
	this->btn_from_file->resize(20, 20);

	connect(this->btn_from_file, SIGNAL(clicked()), this, SLOT(importFromFile()));
}

/**
 * Destructor.
 */
CostumeNew::~CostumeNew() {

}

/**
 * Select and import image.
 */
void CostumeNew::importFromFile() {
	QFileDialog *file_dialog = new QFileDialog(this);
	file_dialog->setWindowTitle("Import costume from file");
	file_dialog->setNameFilter("Image files (*.png *.jpg *.jpeg)");
	file_dialog->setViewMode(QFileDialog::ViewMode::List);
	file_dialog->show();
	// If select file
	if (file_dialog->exec()) {
		std::string file_name = file_dialog->selectedFiles().at(0).toStdString();
		// Load image and create costume
		ScratchCostume costume(ScratchMain.ResourceControl.LoadResourcePhoto(file_name));
		// Add costume to object
		AppWindow->EditArea->Object->CostumeList.push_back(costume);
		// Reload frame
		AppWindow->EditArea->CostumePart->costume_list->reload();
	}
}
