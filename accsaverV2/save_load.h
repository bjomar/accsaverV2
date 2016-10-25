#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <qobject.h>
#include "imcludes.h"
#include "keywindow.h"

class save_load
{
public:
	save_load(keyWindow* encryptKeyWin);

	void save(int, QString, QString);
	void load(int, QLineEdit*, QLineEdit*);

private:
	std::string en_deCrypt(std::string);
	
	QClipboard* clip = QApplication::clipboard();

	keyWindow* encryptKeyWin;
};

#endif // SAVE_LOAD_H
