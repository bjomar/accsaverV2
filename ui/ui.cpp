#include "ui.h"

void ui::setupUI(QWidget* parent)
{
#pragma region setParents

	mb = new QMessageBox(parent);
	save_loadBtn = new QPushButton("LOAD", parent);
	saveCB = new QCheckBox("save", parent);
	menuBar = new QMenuBar(parent);
	optionMenu = new QMenu("options", parent);
	toggleStyle = new QAction("toggle Style", parent);
	changeEncrytionKey = new QAction("change Key", parent);
	IDedit = new QSpinBox(parent);
	accountNameEdit = new QLineEdit(parent);
	passEdit = new QLineEdit(parent);
	mainLayout = new QGridLayout(parent);
	_layout = new QFormLayout(parent);

#pragma endregion

#pragma region prework

	passEdit->setEchoMode(QLineEdit::Password);
	
	optionMenu->addAction(toggleStyle);
	optionMenu->addAction(changeEncrytionKey);

	menuBar->addMenu(optionMenu);
	
#pragma endregion
	
#pragma region UI

	mainLayout->setColumnStretch(0, 1);
	mainLayout->setRowStretch(1, 1);

	_layout->addRow("ID:", IDedit);
	_layout->addRow("name:", accountNameEdit);
	_layout->addRow("pass:", passEdit);

	mainLayout->addWidget(menuBar, 0, 0, 1, 0);
	mainLayout->addLayout(_layout, 1, 0, 1, 0);
	mainLayout->addWidget(saveCB, 2, 0, Qt::AlignRight);
	mainLayout->addWidget(save_loadBtn, 2, 1, Qt::AlignRight);

#pragma endregion
}