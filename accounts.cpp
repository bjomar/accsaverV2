#include "accounts.h"


accounts::accounts()
{}

void accounts::load_from_file(const char* path)
{
    std::fstream f;

    f.open(path, std::ios::in);
    std::string accN, pass;

    while (!f.eof())
    {
        f >> accN;
        f >> pass;

        this->add(accN.c_str(), pass.c_str());

        accN = "";
        pass = "";
    }

    //because, i dont know why, there is always an empty one at the end, so we erase it
    //i think it might be some sort of failure in the saving process, but this fixes it.
    //but, i rather do this than rewriting the save and load process.
    this->account_list.erase(account_list.end());

    /*
    QFile f(path);
    if(f.open(QFile::ReadOnly))
    {
        QString all = f.readAll();

        //[0] = name [1] = pw ; and repeating
        auto aclist = all.split('\r');

        if(aclist.size() > 0)
        {
            for(uint i = 0; i < (uint)aclist.size()-1;)
            {
                this->add(aclist.at(i++), aclist.at(i++));
            }
        }
    }
    f.close();
    */
}

void accounts::safe(const char* path)
{
    //this safe and load method does not always work so good, but on most occaisions it works pretty well
    //maybe it wil be changed someday
    std::fstream f;

    f.open(path, std::ios::out);

    for(uint i = 0; i < this->account_list.size(); i++)
        f << this->account_list.at(i).first.toStdString() << " " << this->account_list.at(i).second.toStdString() << std::endl;

    f.close();

    /*
    QFile f(path);
    if(f.open(QFile::WriteOnly))
    {
        for(uint i = 0; i < this->account_list.size(); i++)
        {
            f.write(QString(this->account_list.at(i).first + '\r' + this->account_list.at(i).second).toUtf8());
        }
    }
    f.close();
    */
}

void accounts::add(QString name, QString password)
{
    this->account_list.push_back(std::pair<QString, QString>(name, password));
}

void accounts::delete_entry(int index)
{
    account_list.erase(account_list.begin() + index);
}

std::pair<QString, QString>& accounts::operator[](int i)
{
    return this->account_list.at(i);
}

uint accounts::count()
{
    return this->account_list.size();
}
