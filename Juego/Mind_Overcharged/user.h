#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QString>
#include <string.h>
#include <iostream>
#include <fstream>
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
    int option;

private slots:
    void on_pushButton_clicked();

private:
    Ui::User *ui;
    void escribir(string dir, string txt);
    string dirUser = "../Usuarios/dirUsers";
    bool valuser(string nameusu, string claveusu);
};

#endif // USER_H
