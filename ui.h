#ifndef UI_H
#define UI_H

#include "main.h"
#include "accounts.h"

namespace Ui {
class UI;
}

class UI : public QWidget
{
    Q_OBJECT

public:
    explicit UI(QWidget *parent = 0);
    ~UI();

private:
    void update_accountlist();
    void load_settings(const char *file);
    void safe_settings(const char *file);

private:
    Ui::UI *ui;
    accounts _accounts;

    QClipboard* clip; //= QApplication::clipboard();
};

#endif // UI_H
