#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QKeyEvent>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;

    bool GameScreen;
    bool Multiplayer;

    QList<QList<Qt::Key>> PlayerKeys;
    QList<Qt::Key> P1K, P2K;

    // QList<Entity> Entities;

};
#endif // MAINWINDOW_H
