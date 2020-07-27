#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("Mind Overcharged");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_BNuevo_clicked()
{

}

void Menu::on_BCargar_clicked()
{

}

void Menu::on_BMultiplayer_clicked()
{

}
