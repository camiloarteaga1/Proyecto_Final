#ifndef MENU_H
#define MENU_H

#include <QDialog>

#include "multiplayer.h"
#include "nivl1.h"
#include "nivel2.h"
#include "nivel3.h"

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
};

#endif // MENU_H
