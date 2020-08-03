#ifndef FINAL_H
#define FINAL_H

#include <QDialog>

namespace Ui {
class Final;
}

class Final : public QDialog
{
    Q_OBJECT

public:
    explicit Final(QWidget *parent = nullptr);
    ~Final();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Final *ui;
};

#endif // FINAL_H
