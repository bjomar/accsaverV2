#ifndef UI_H
#define UI_H

#include "ui_global.h"

/*accsaverV2 Copyright (C) 2016 Björn Marx*/

class __declspec(dllexport) ui
{
protected:

	void setupUI(QWidget*);

	QMessageBox* mb;
	QCheckBox* saveCB;
	QPushButton* save_loadBtn;

	QMenuBar* menuBar;
	QMenu* optionMenu;
	QAction* toggleStyle;
	QAction* changeEncrytionKey;

	QSpinBox* IDedit;
	QLineEdit* accountNameEdit;
	QLineEdit* passEdit;

	QGridLayout* mainLayout;
	QFormLayout* _layout;
};

#endif // UI_H
