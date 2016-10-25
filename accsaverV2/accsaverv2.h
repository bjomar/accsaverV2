/*accsaverV2 Copyright (C) 2016 Bjön Marx*/

#ifndef ACCSAVERV2_H
#define ACCSAVERV2_H

#include "imcludes.h"
#include "save_load.h"
#include "keywindow.h"

class accsaverV2 : public QWidget, private ui
{
	Q_OBJECT

public:
	accsaverV2(QWidget *parent = 0);
	~accsaverV2();

private:
	keyWindow* keyWin;
	save_load* saveOrLoad;

	void btn_save();
	void btn_load();

	void stylesheet();
	void initConnects();
	
	bool defaultStyle = false;
};

#endif // ACCSAVERV2_H