#ifndef SHIP_H
#define SHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "color.h"

class CShip : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CShip(EColor eColor, QGraphicsItem* pParent = nullptr);

    void Shoot();

    EColor GetColor() const;
    void SetColor(EColor eColor);

signals:
    void sigIncreaseScore();
    void sigDecreaseScore();

private:
    EColor m_eColor;
};

#endif // SHIP_H
