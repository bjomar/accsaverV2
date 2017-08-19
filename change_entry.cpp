#include "change_entry.h"
#include "ui_change_entry.h"

change_entry::change_entry(accounts::account& ac_to_change, QString key, QWidget *parent) : QWidget(parent), ui(new Ui::change_entry), _ac_to_change(ac_to_change)
{
    this->setWindowFlags(Qt::Window);

    ui->setupUi(this);

    this->setLayout(ui->gridLayout);

    _key = key;

    ui->ledit_username->setText(edcryption(_ac_to_change.first, _key));
    ui->ledit_password->setText(edcryption(_ac_to_change.second, _key));

    this->setWindowTitle(ui->ledit_username->text());

    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        _ac_to_change.first = edcryption(ui->ledit_username->text(), _key);
        _ac_to_change.second = edcryption(ui->ledit_password->text(), _key);

        this->destroy();
    });
}

change_entry::~change_entry()
{
    delete ui;
}
