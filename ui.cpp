#include "ui.h"
#include "ui_ui.h" //nice auto generated name.

UI::UI(QWidget *parent) : QWidget(parent), ui(new Ui::UI) {
    ui->setupUi(this);

    //assinging layouts... cuz the designer did not... thanks Qt
    this->ui->load_tab->setLayout(this->ui->layout_load_page);
    this->ui->manage_tab->setLayout(this->ui->layout_manage_page);
    this->ui->gbox_add_account->setLayout(this->ui->layout_add_account);
    this->ui->gbox_key->setLayout(this->ui->layout_key);

    //pre use operations
    this->clip = QApplication::clipboard();
    this->load_settings("settings.txt");
    this->_accounts.load_from_file("save.txt");
    this->ui->rbutton_direct_login->setChecked(true);

    QFile f("style.qss");

    if(f.open(QFile::ReadOnly))
       this->setStyleSheet(f.readAll());

    f.close();

    //adding accounts to list
    this->update_accountlist();

    //connections
    this->connect(this->ui->btn_add_account, &QPushButton::clicked, this, [=]() {
        this->_accounts.add(edcryption(this->ui->ledit_name->text(), this->ui->ledit_key->text()),
                            edcryption(this->ui->ledit_password->text(), this->ui->ledit_key->text()));

        this->update_accountlist();
        this->ui->ledit_name->setText("");
        this->ui->ledit_password->setText("");
    });

    this->connect(ui->btn_change_entry, &QPushButton::clicked, this, [=](){
        change_entry* ce = new change_entry(_accounts[ui->account_list->currentRow()], ui->ledit_key->text(), this);

        ce->show();
    });

    this->connect(ui->btn_delete_entry, &QPushButton::clicked, this, [=](){
        _accounts.delete_entry(ui->account_list->currentRow());

        this->update_accountlist();
    });

    this->connect(this->ui->account_list, &QListWidget::doubleClicked, this, [=]() {
        if(this->ui->rbutton_cpy_pw->isChecked()) //cpy password
            clip->setText(edcryption(this->_accounts[this->ui->account_list->currentRow()].second, this->ui->ledit_key->text()));
        else //login directly
        {
            system("taskkill /F /IM steam.exe"); //evil system command

            QString login, pass;

            login = edcryption(this->_accounts[this->ui->account_list->currentRow()].first, this->ui->ledit_key->text());
            pass = edcryption(this->_accounts[this->ui->account_list->currentRow()].second, this->ui->ledit_key->text());

            QStringList args;
            args << "-login" << login << pass;

            //hexenwerk
            QProcess::startDetached(this->ui->ledit_steam_path->text(), args);
        }
    });

    this->connect(this->ui->btn_update_settings, &QPushButton::clicked, this, [=](){
        this->safe_settings("settings.txt");
    });
}

UI::~UI() {
    //yes, it actually only saves when you quit it
    this->_accounts.safe("save.txt");
    delete ui;
}

/// updates ui->account_list
void UI::update_accountlist() {
    this->ui->account_list->clear();

    for(uint i = 0; i < this->_accounts.count(); i++)
        this->ui->account_list->addItem(edcryption(this->_accounts[i].first, this->ui->ledit_key->text()));
}

void UI::load_settings(const char* file) {
    QFile f(file);
    if(!f.open(QFile::ReadOnly))
        return;

    QString b = f.readAll();

    QStringList bl = b.split(QChar('\r'));

    this->ui->ledit_key->setText(bl[0]);
    this->ui->ledit_steam_path->setText(bl[1]);

    f.close();
}

void UI::safe_settings(const char *file) {
    QFile f(file);
    if(!f.open(QFile::WriteOnly))
        return;

    f.write(QString(this->ui->ledit_key->text() + '\r' + this->ui->ledit_steam_path->text()).toUtf8());

    f.close();
}
