#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "color.h"

class CBullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CBullet(EColor eColor, QGraphicsItem* pParent = nullptr);

    EColor GetColor() const;
    void SetColor(EColor eColor);

signals:
    void sigIncreaseScore();
    void sigDecreaseScore();

public slots:
    void onMove();

private:
    EColor m_eColor;
};

#endif // BULLET_H
