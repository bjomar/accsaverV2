/*accsaverV2 Copyright (C) 2016 Bjön Marx*/

#ifndef KEYWINDOW_H
#define KEYWINDOW_H

#include "imcludes.h"

class keyWindow : public QWidget, private ui_key
{
	Q_OBJECT

public:
	keyWindow(QWidget *parent = 0);
	~keyWindow();

	//on wish of krokoklemme
	QLineEdit* key(int) const;

private:
	void getKeys();
};

#endif // KEYWINDOW_H
