#ifndef POINTS_H
#define POINTS_H

#include <QGraphicsTextItem>

#include "settings.h"

class CPoints: public QGraphicsTextItem {
public:
    CPoints(QGraphicsItem *pParent = nullptr);

    void IncreaseScore();
    void DecreaseScore();
    void DecreaseHealth();

    int GetHealth() const;
    int GetScore() const;

    void Reset();

private:
    int m_nHealth = gMaxHealth;
    int m_nScore = 0;
};

#endif // POINTS_H
