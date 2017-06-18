#include "ui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UI w;

    w.show();

    return a.exec();
}

QString edcryption(QString s, QString key)
{
    QString b;

    for (int i = 0; i < s.length(); i++)
    {
        if(i % 2 == 0)
            b += QChar(~s[i].unicode() ^ key[i % key.length()].unicode());
        else
            b += QChar(s[i].unicode() ^ ~key[i % key.length()].unicode());
    }

    return b;
}
