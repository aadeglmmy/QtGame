#include <QTimer>

#include <QGraphicsScene>

#include "alien.h"
#include "settings.h"
#include "ship.h"

CAlien::CAlien(EColor eColor, QGraphicsItem *pParent) : QGraphicsPixmapItem(pParent) {
    SetColor(eColor);

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &CAlien::onMove);
    pTimer->start(gAlienSpeed);
}

EColor CAlien::GetColor() const {
    return m_eColor;
}

void CAlien::SetColor(EColor eColor) {
    m_eColor = eColor;

    switch(eColor) {
    case EColor::Red: {
        QPixmap oPixMap(":/Resources/RedAlien.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Pink: {
        QPixmap oPixMap(":/Resources/PinkAlien.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Blue: {
        QPixmap oPixMap(":/Resources/BlueAlien.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    }
}

void CAlien::onMove() {
    setPos(x(), y() + 5);

    if(pos().y() >= (scene() -> height() - gShipSize.height())) {
        scene()->removeItem(this);
        emit sigDecreaseHealth();
        delete this;
    }

    QList<QGraphicsItem*> lstCollidingItem = collidingItems();

    for (auto const pItem : lstCollidingItem) {
        if (dynamic_cast<CShip*>(pItem)) {
            emit sigGameOver();
        }
    }
}
