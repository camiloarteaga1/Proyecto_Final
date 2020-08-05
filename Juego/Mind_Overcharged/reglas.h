#ifndef REGLAS_H
#define REGLAS_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class Reglas;
}

class Reglas : public QDialog
{
    Q_OBJECT

public:
    explicit Reglas(QWidget *parent = nullptr);
    ~Reglas();

private slots:
    void on_Volver_clicked();

private:
    Ui::Reglas *ui;

    class Menu *volv;
};

#endif // REGLAS_H
