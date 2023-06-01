#include <QTimer>

#include <QGraphicsScene>

#include "alien.h"
#include "bullet.h"
#include "settings.h"

CBullet::CBullet(EColor eColor, QGraphicsItem *pParent) : QGraphicsPixmapItem(pParent) {
    SetColor(eColor);

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &CBullet::onMove);
    pTimer->start(gBulletSpeed);
}

EColor CBullet::GetColor() const {
    return m_eColor;
}

void CBullet::SetColor(EColor eColor) {
    m_eColor = eColor;

    switch(eColor) {
    case EColor::Red: {
        QPixmap oPixMap(":/Resources/RedBullet.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Pink: {
        QPixmap oPixMap(":/Resources/PinkBullet.png");
        setPixmap(oPixMap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    case EColor::Blue: {
        QPixmap oPixmap(":/Resources/BlueBullet.png");
        setPixmap(oPixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
        break;
    }
    }
}

void CBullet::onMove() {
    QList<QGraphicsItem*> lstCollidingItem = collidingItems();

    for(auto const pItem : lstCollidingItem) {
        CAlien* pAlien = dynamic_cast<CAlien*>(pItem);
        if (pAlien != nullptr) {
            if (pAlien->GetColor() == GetColor()) {
                scene()->removeItem(pAlien);
                scene()->removeItem(this);

                emit sigIncreaseScore();

                delete pAlien;
                delete this;
            } else {
                emit sigDecreaseScore();
                scene()->removeItem(this);
                delete this;
            }
            return;
        }
    }

    setPos(x(), y() - 10);

    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
