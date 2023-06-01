#ifndef ALIEN_H
#define ALIEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

#include "color.h"

class CAlien : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CAlien(EColor eColor, QGraphicsItem* pParent = nullptr);

    EColor GetColor() const;
    void SetColor(EColor eColor);

signals:
    void sigDecreaseHealth();
    void sigGameOver();

public slots:
    void onMove();

private:
    EColor m_eColor;
};

#endif // ALIEN_H
