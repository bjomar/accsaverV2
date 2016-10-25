/*accsaverV2 Copyright (C) 2016 Bjön Marx*/

#include "accsaverv2.h"

accsaverV2::accsaverV2(QWidget *parent)
	: QWidget(parent)
{
	this->setMaximumHeight(1);

	setupUI(this);
	setLayout(mainLayout);

	mb->setIcon(QMessageBox::Warning);
	saveCB->setChecked(false);
	passEdit->setReadOnly(true);

	keyWin = new keyWindow(this);
	saveOrLoad = new save_load(keyWin);

	initConnects();
	try
	{
		this->stylesheet();
	}
	catch (const std::exception* e)
	{
		mb->setWindowTitle("error");
		mb->setText(e->what());
		mb->show();

		delete e;
	}
}

accsaverV2::~accsaverV2()
{
	delete mb, saveCB, save_loadBtn, menuBar,
		changeEncrytionKey, IDedit, accountNameEdit,
		passEdit, _layout, mainLayout;

	delete keyWin, saveOrLoad;
}

void accsaverV2::btn_save()
{
	try
	{
		saveOrLoad->save(IDedit->value(), accountNameEdit->text(), passEdit->text());
	}
	catch (const std::exception* e)
	{
		mb->setWindowTitle("error");
		mb->setText(e->what());
		mb->show();

		delete e;
	}
}

void accsaverV2::btn_load()
{
	try
	{
		saveOrLoad->load(IDedit->value(), accountNameEdit, passEdit);
	}
	catch (const std::exception* e)
	{
		mb->setWindowTitle("error");
		mb->setText(e->what());
		mb->show();

		delete e;
	}
}

void accsaverV2::stylesheet()
{
	QFile f("style.qss");
	
	if (f.open(QFile::ReadOnly))
		this->setStyleSheet(f.readAll());
	else
		throw new std::exception("style.qss not found!");

	f.close();
}

void accsaverV2::initConnects()
{
	//just that its connect at all when programm starts
	connect(save_loadBtn, &QPushButton::clicked, this, &accsaverV2::btn_load);

	//toggels stylesheet
	connect(toggleStyle, &QAction::triggered, this, [=]()
	{
		if (!defaultStyle)
		{
			this->setStyleSheet("");
			defaultStyle = !defaultStyle;
		}
		else
		{
			try
			{
				stylesheet();
			}
			catch (const std::exception* e)
			{
				mb->setWindowTitle("error");
				mb->setText(e->what());
				mb->show();

				delete e;
			}
			defaultStyle = !defaultStyle;
		}
	});

	//toggels the save and load button
	connect(saveCB, &QCheckBox::clicked, this, [=]()
	{
		if (saveCB->isChecked())
		{
			save_loadBtn->disconnect();
			save_loadBtn->setText("SAVE");
			passEdit->setReadOnly(!true);
			connect(save_loadBtn, &QPushButton::clicked, this, &accsaverV2::btn_save);
		}
		else
		{
			save_loadBtn->disconnect();
			save_loadBtn->setText("LOAD");
			passEdit->setReadOnly(true);
			connect(save_loadBtn, &QPushButton::clicked, this, &accsaverV2::btn_load);
		}
	});

	connect(changeEncrytionKey, &QAction::triggered, this, [=]()
	{
		keyWin->show();
	});
}