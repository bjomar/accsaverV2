/*accsaverV2 Copyright (C) 2016 Bjön Marx*/

#ifndef UI_KEY_H
#define UI_KEY_H

#include "ui_global.h"

class __declspec(dllexport) ui_key
{
protected:
	void setupUI(QWidget* parent);

	QPushButton* setBtn;
	QLineEdit* key1Edit;
	QLineEdit* key2Edit;

	QFormLayout* fl;
};

#endif // !UI_KEY_H