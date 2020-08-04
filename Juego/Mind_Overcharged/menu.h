#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QMessageBox>

#include "user.h"
#include "multiplayer.h"
#include "nivl1.h"
#include "nivl2.h"
//#include "nivel3.h"

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

private:
    Ui::Menu *ui;

    Multiplayer *multi;
    Nivl1 * nivel1;
    Nivl2 * nivel2;
    class User * user;
};

#endif // MENU_H
