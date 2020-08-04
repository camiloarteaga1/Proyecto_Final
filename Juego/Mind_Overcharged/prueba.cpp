#include "prueba.h"
#include "ui_prueba.h"

prueba::prueba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prueba)
{
    ui->setupUi(this);
}

prueba::~prueba()
{
    delete ui;
}
