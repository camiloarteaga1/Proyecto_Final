#include "final.h"
#include "ui_final.h"

#include <QProcess>

Final::Final(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Final)
{
    ui->setupUi(this);
}

Final::~Final()
{
    delete ui;
}

void Final::on_pushButton_clicked()
{
    qApp->quit();
}
