#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QKeyEvent>
#include <user.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *Event);
    ~MainWindow();
    QList <int> datauser;

private slots:
    void on_BRegister_clicked();

    void on_BInicio_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;

    bool GameScreen;
    bool Multiplayer;

    QList<QList<Qt::Key>> PlayerKeys;
    QList<Qt::Key> P1K, P2K;

    User *usuario;

    // QList<Entity> Entities;

    int lifes, lvl;

};
#endif // MAINWINDOW_H
