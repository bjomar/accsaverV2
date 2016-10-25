#include "keywindow.h"

keyWindow::keyWindow(QWidget *parent)
	: QWidget(parent)
{
	setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

	setupUI(this);
	
	setLayout(fl);
	
	getKeys();

	connect(setBtn, &QPushButton::clicked, this, [=]()
	{
		std::fstream f;
		f.open("keys.accV2", std::ios::out);

		f << key1Edit->text().toStdString() << std::endl;
		f << key2Edit->text().toStdString() << std::endl;

		f.close();
	});
}

keyWindow::~keyWindow()
{

}

QLineEdit * keyWindow::key(int wich) const
{
	if (wich == 1)
		return key1Edit;
	if (wich == 2)
		return key2Edit;
}

void keyWindow::getKeys()
{
	std::fstream f;
	f.open("keys.accV2", std::ios::in);

	std::string buf;

	f >> buf;
	key1Edit->setText(buf.c_str());
	f >> buf;
	key2Edit->setText(buf.c_str());

	f.close();
}