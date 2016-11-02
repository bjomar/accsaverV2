/*accsaverV2 Copyright (C) 2016 Björn Marx*/

#ifndef INCLUDES_H
#define INCLUDES_H

#include <qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qfile.h>
#include <qhash.h>
#include <qmenubar.h>
#include <qspinbox.h>
#include <qformlayout.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qfile.h>
#include <qcheckbox.h>
#include <qbytearray.h>
#include <qicon.h>
#include <qexception.h>
#include <qclipboard.h>

#include <exception>
#include <fstream>

#pragma region IMPORTS

class __declspec(dllimport) ui_key
{
protected:
	void setupUI(QWidget* parent);

	QPushButton* setBtn;
	QLineEdit* key1Edit;
	QLineEdit* key2Edit;

	QFormLayout* fl;
};

class __declspec(dllimport) ui
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

#pragma endregion


#endif // !INCLUDES_H