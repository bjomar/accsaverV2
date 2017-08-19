#ifndef CHANGE_ENTRY_H
#define CHANGE_ENTRY_H

#include "main.h"
#include <accounts.h>

namespace Ui {
class change_entry;
}

class change_entry : public QWidget
{
    Q_OBJECT

public:
    explicit change_entry(accounts::account& ac_to_change, QString key, QWidget *parent = 0);
    ~change_entry();

private:
    Ui::change_entry *ui;

    QString _key;
    accounts::account& _ac_to_change;
};

#endif // CHANGE_ENTRY_H
