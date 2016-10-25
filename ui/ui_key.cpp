#include "ui_key.h"

void ui_key::setupUI(QWidget * parent)
{
	setBtn = new QPushButton("set keys", parent);
	key1Edit = new QLineEdit(parent);
	key2Edit = new QLineEdit(parent);

	fl = new QFormLayout(parent);

	fl->addRow("key1", key1Edit);
	fl->addRow("key2", key2Edit);
	fl->addRow(setBtn);
}