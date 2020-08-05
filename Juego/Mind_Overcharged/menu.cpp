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
    nivel1 = new Nivl1();
    nivel1->UserName = this->UserName;
    nivel1->show();
    this->hide();
}

void Menu::on_BCargar_clicked()
{

    if (lvl == 2){
        nivel2 = new Nivl2();
        nivel2->vidas = vid;
        nivel2->UserName = this->UserName;
        nivel2->show();
        this->hide();
    }

    else if (lvl == 1){
        nivel1 = new Nivl1();
        nivel1->UserName = this->UserName;
        nivel1->show();
        this->hide();
    }

    else{
        QMessageBox::warning(this, "Warning", "El usuario no tiene ninguna partida guardad");
        return;
    }
}

void Menu::on_BMultiplayer_clicked()
{
    multi = new Multiplayer(this);
    multi->exec();
    this->hide();
}

void Menu::on_reglas_clicked()
{
    reglas = new Reglas();
    reglas->show();
    this->hide();
}
