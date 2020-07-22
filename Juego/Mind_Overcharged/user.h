#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QString>
#include <string.h>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <vector>
using namespace std;

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    int option, vidas, level;
    void overload(string life, string level, string user);
//    void overwritedata(QList <int> *data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::User *ui;
    void escribir(string dir, string txt);
    string dirUser = "../Users/dirUsers.txt";
    string dirtemp = "../Users/dirTemp.txt";
    vector <int> valuser(string nameusu, string claveusu);

    template <typename T>
    void borrar(T dir);

    template<typename T>
    void rename(T dirtemp, T dircamb);
};

#endif // USER_H
