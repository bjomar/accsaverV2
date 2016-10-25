#include "accsaverv2.h"
#include <QtWidgets/QApplication>

/*
* accsaverV2 Copyright (C) 2016 Bjön Marx
*
* known problems:
*	load wont work if encryption generateds an return if thats the case -> cange the key - might be fixed someday
*	same id can be saved more than once, only the first counts
*
* todo:
*	fix crash when calling 'show' function @ keyWin - done!
*	fix encryptionkey window layout - done!
*	fix wrongly thrown exception while saving (it still saves anyways) - done!
*	
*	fix stylesheet so the menu in menubar isnt invisible - done!
*
*	outsource stylesheet - done!
*
* add:
*	add possibility to save new keys (button in keywindow) - done!
*	copy pass to clipboard after loading or add buttons to do so - done! (gets copied after loading)
*
* wishes:
*	eventaully get this a little fancy - by myself - done!
*/

//( ͡° ͜ʖ ͡°)
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	accsaverV2 w;

	w.show();
	
	return a.exec();
}