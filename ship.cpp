#include <QGraphicsScene>

#include "bullet.h"
#include "ship.h"

CShip::CShip(EColor eColor, QGraphicsItem *pParent) : QGraphicsPixmapItem(pParent) {
    SetColor(eColor);
}

void CShip::Shoot() {
    CBullet* pBullet = new CBullet(m_eColor);
    connect(pBullet, &CBullet::sigIncreaseScore, this, &CShip::sigIncreaseScore);
    connect(pBullet, &CBullet::sigDecreaseScore, this, &CShip::sigDecreaseScore);

    pBullet->setPos(x() + 27, y() - 10);
    scene()->addItem(pBullet);
}

EColor CShip::GetColor() const {
    return m_eColor;
}

void CShip::SetColor(EColor eColor) {
    m_eColor = eColor;

    switch(eColor) {
    case EColor::Red: {
        QPixmap oPixMap(":/Resources/RedShip.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Pink: {
        QPixmap oPixMap(":/Resources/PinkShip.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Blue: {
        QPixmap oPixMap(":/Resources/BlueShip.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    default: {
        QPixmap oPixMap(":/Resources/RedShip.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        m_eColor = EColor::Red;
        break;
    }
    }
}
