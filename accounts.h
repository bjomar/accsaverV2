#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "main.h"

class accounts
{
public:
    accounts();

    void load_from_file(const char *path);
    void safe(const char *path);

    void add(QString name, QString password);

    std::pair<QString, QString>& operator[](const int i);

    uint count();

private:
    // .first = name & .second = password
    std::vector<std::pair<QString, QString>> account_list;
};

#endif // ACCOUNTS_H
