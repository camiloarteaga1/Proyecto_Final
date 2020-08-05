#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QString>
#include <string.h>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <vector>
#include "menu.h"
#include "archivos.h"
using namespace std;

namespace Ui {
class User;
}

class User : public QDialog, public Archivos
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    void overload(string life, string level, string user);
//    void overwritedata(QList <int> *data);

    int option, vidas, level;

private slots:
    void on_pushButton_clicked();

private:
    Ui::User *ui;

    string dirUser = "../Users/dirUsers.txt";
    string dirtemp = "../Users/dirTemp.txt";
    vector <int> valuser(string nameusu, string claveusu);

public:
    QString name;

};

#endif // USER_H
