#include <QFont>

#include "points.h"

CPoints::CPoints(QGraphicsItem *pParent) : QGraphicsTextItem(pParent) {
    setPlainText(QString("Health: ") + QString::number(m_nHealth) + '\n' + QString("Score: ") + QString::number(m_nScore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 24));
}

void CPoints::IncreaseScore() {
    m_nScore += 50;
    setPlainText(QString("Health: ") + QString::number(m_nHealth) + '\n' + QString("Score: ") + QString::number(m_nScore));
}

void CPoints::DecreaseScore() {
    m_nScore -= 50;
    setPlainText(QString("Health: ") + QString::number(m_nHealth) + '\n' + QString("Score: ") + QString::number(m_nScore));
}

void CPoints::DecreaseHealth() {
    --m_nHealth;
    setPlainText(QString("Health: ") + QString::number(m_nHealth) + '\n' + QString("Score: ") + QString::number(m_nScore));
}

int CPoints::GetHealth() const {
    return m_nHealth;
}

int CPoints::GetScore() const {
    return m_nScore;
}

void CPoints::Reset() {
    m_nScore = 0;
    m_nHealth = gMaxHealth;
    setPlainText(QString("Health: ") + QString::number(m_nHealth) + '\n' + QString("Score: ") + QString::number(m_nScore));
}
