#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QDialog>

namespace Ui {
class Multiplayer;
}

class Multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = nullptr);
    ~Multiplayer();

private:
    Ui::Multiplayer *ui;
};

#endif // MULTIPLAYER_H
