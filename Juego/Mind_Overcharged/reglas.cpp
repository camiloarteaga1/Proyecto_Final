#include "reglas.h"
#include "ui_reglas.h"

Reglas::Reglas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reglas)
{
    ui->setupUi(this);
    setWindowTitle("Da Rules");
}

Reglas::~Reglas()
{
    delete ui;
}

void Reglas::on_Volver_clicked()
{
    volv = new Menu();
    volv->show();
    this->hide();
}
