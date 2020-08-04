#ifndef PRUEBA_H
#define PRUEBA_H

#include <QWidget>

namespace Ui {
class prueba;
}

class prueba : public QWidget
{
    Q_OBJECT

public:
    explicit prueba(QWidget *parent = nullptr);
    ~prueba();

private:
    Ui::prueba *ui;
};

#endif // PRUEBA_H
