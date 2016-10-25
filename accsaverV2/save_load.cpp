/*accsaverV2 Copyright (C) 2016 Bjön Marx*/

#include "save_load.h"

save_load::save_load(keyWindow* encryptKeyWin)
{
	this->encryptKeyWin = encryptKeyWin;
}

void save_load::save(int id, QString accName, QString pass)
{
	if (accName.isEmpty() || pass.isEmpty())
		throw new std::exception("name or pass empty!");

	std::fstream f;
	
	f.open("data.accV2", std::ios::app);

	f << id << " " << en_deCrypt(accName.toStdString()) << " " << en_deCrypt(pass.toStdString()) << std::endl;

	f.close();		
}

void save_load::load(int id, QLineEdit* accNE, QLineEdit* passE)
{
	std::fstream f;
	
	f.open("data.accV2", std::ios::in);

	int id_fromFile;
	std::string accN, pass;

	while (!f.eof())
	{
		f >> id_fromFile;
		f >> accN;
		f >> pass;

		if (id_fromFile == id)
		{
			accNE->setText(QString::fromStdString(en_deCrypt(accN)));
			passE->setText(QString::fromStdString(en_deCrypt(pass)));

			clip->setText(passE->text());

			return;
		}
	}
	throw new std::exception("not found");
}

//XOR encryption
std::string save_load::en_deCrypt(std::string s)
{
	std::string h,
		key = encryptKeyWin->key(1)->text().toStdString(),
		key2 = encryptKeyWin->key(2)->text().toStdString();

	srand((int)key.at(0) ^ (int)key2.at(key2.length() - 1));

	for (size_t i = 0; i < s.length(); i++)
	{
		h.push_back(s.at(i) ^ (key.at(i % key.length() & rand() % key.length()) ^ -key2.at(i % key2.length() | rand() % key2.length())));
	}
	return h;
}