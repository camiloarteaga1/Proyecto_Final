#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Platform: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Platform(float Friction = 1, bool IsSolid = 1,  QString FileName = "", bool IsConductive = 0, QGraphicsItem * = nullptr);

    void setIsPlayerOnTop(bool Status);
    void setIsCharged(bool Status);
    void AddPlayersQueue(short &Id);
    void setSpecialFunct(void(*)());
    void setMode(short Mode);

    bool getIsConductive();
    bool getIsPlayerOnTop();
    bool getIsCharged();
    double getFriction();
    bool IsSolid();

    void DischargeStart(int TimeMls = 100);
    void DischargeStop();

    void TransparentStart(int TimeMls = 1500);
    void TransparentStop();

    void ConductStart(int TimeMls = 100);
    void ConductStop();

public slots:
    void Conductivity();
    void DisableCharge();
    void setTransparent();

private:
    const double Friction;
    const bool Solid;
    const bool Conductive;

    bool isActive;
    bool isPlayerOn;
    /// 0: Deactivate, 1: Activate, 2: Waiting
    short Mode;

    QTimer *DischargeTimer;
    QTimer *TransparentTimer;
    QTimer *ConductTimer;

    QList<short> AllowIDs;

    /// Lambda

    void(*SpecialFunct)();


};

#endif // PLATFORM_H
