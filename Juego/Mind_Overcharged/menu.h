#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QMessageBox>
#include <string>
#include <iostream>

#include "user.h"
#include "multiplayer.h"
#include "nivl1.h"
#include "nivl2.h"
#include "reglas.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_BNuevo_clicked();

    void on_BCargar_clicked();

    void on_BMultiplayer_clicked();

    void on_reglas_clicked();

private:
    Ui::Menu *ui;

    //To show the game levels
    class Multiplayer *multi;
    class Nivl1 * nivel1;
    class Nivl2 * nivel2;
    class User * user;
    class Reglas *reglas;

public:
    std::string UserName;
    int vid, lvl;

};

#endif // MENU_H
