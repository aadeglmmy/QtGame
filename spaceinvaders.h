#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <QGraphicsView>

#include "points.h"
#include "ship.h"

class CSpaceInvaders : public QGraphicsView {
    Q_OBJECT
public:
    CSpaceInvaders(QSize oScreenSize, QWidget* pParent = nullptr);

    void Run();
    void CheckPoints();

protected:
    void keyPressEvent(QKeyEvent* pEvent) override;

public slots:
    void onCreateEnemy();
    void onIncreaseScore();
    void onDecreaseScore();
    void onDecreaseHealth();
    void onGameOver();

private:
    CShip* m_pShip = nullptr;
    CPoints* m_pPoints = nullptr;
    QSize m_oScreenSize;
};

#endif // SPACEINVADERS_H
