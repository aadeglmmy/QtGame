#include <QKeyEvent>
#include <QTimer>

#include "alien.h"
#include "spaceinvaders.h"

CSpaceInvaders::CSpaceInvaders(QSize oScreenSize, QWidget *pParent) : QGraphicsView(pParent), m_oScreenSize(oScreenSize) {
    QGraphicsScene* pScene = new QGraphicsScene();
    setScene(pScene);

    pScene->setSceneRect(0,0,m_oScreenSize.width(), m_oScreenSize.height());

    setBackgroundBrush(QBrush(QImage(":/Resources/Background.jpg")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursor(Qt::PointingHandCursor);
    setStyleSheet("border-style:none");
}

void CSpaceInvaders::Run() {
    scene()->clear();
    setCursor(Qt::BlankCursor);

    m_pShip = new CShip(EColor::Red);
    m_pShip->setPos(m_oScreenSize.width() / 2, m_oScreenSize.height() - gShipSize.height());
    m_pShip->setFlag(QGraphicsItem::ItemIsFocusable);
    m_pShip->setFocus();
    scene()->addItem(m_pShip);

    connect(m_pShip, &CShip::sigIncreaseScore, this, &CSpaceInvaders::onIncreaseScore);
    connect(m_pShip, &CShip::sigDecreaseScore, this, &CSpaceInvaders::onDecreaseScore);

    m_pPoints = new CPoints();
    scene()->addItem(m_pPoints);

    QTimer* pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &CSpaceInvaders::onCreateEnemy);
    pTimer->start(2000);
}

void CSpaceInvaders::CheckPoints() {
    if ((m_pPoints->GetScore() < 0) || (m_pPoints->GetHealth() <= 0)) {
        m_pPoints->Reset();
        onGameOver();
    }
}

void CSpaceInvaders::keyPressEvent(QKeyEvent *pEvent) {
    if (m_pShip == nullptr) {
        return;
    }

    switch (pEvent->key()) {
    case Qt::Key_Left:
        if (m_pShip->pos().x() > 0) {
            m_pShip->setPos(m_pShip->x() - 20, m_pShip->y());
        }
        break;

    case Qt::Key_Right:
        if ((m_pShip->pos().x() + gShipSize.width()) < m_oScreenSize.width()) {
            m_pShip->setPos(m_pShip->x() + 20, m_pShip->y());
        }
        break;

    case Qt::Key_Z: {
        int nColor = static_cast<int>(m_pShip->GetColor());
        m_pShip->SetColor(static_cast<EColor>(++nColor));
        break;
    }

    case Qt::Key_Space:
        m_pShip->Shoot();
        break;
    }
}

void CSpaceInvaders::onCreateEnemy() {
    int nPos = rand() % (m_oScreenSize.width() - 100);
    int nColor = rand() % 3;

    CAlien *pAlien = new CAlien(static_cast<EColor>(nColor));
    pAlien->setPos(nPos, 0);

    scene()->addItem(pAlien);

    connect(pAlien, &CAlien::sigGameOver, this, &CSpaceInvaders::onGameOver);
    connect(pAlien, &CAlien::sigDecreaseHealth, this, &CSpaceInvaders::onDecreaseHealth);
}

void CSpaceInvaders::onIncreaseScore() {
    m_pPoints->IncreaseScore();
    CheckPoints();
}

void CSpaceInvaders::onDecreaseScore() {
    m_pPoints->DecreaseScore();
    CheckPoints();
}

void CSpaceInvaders::onDecreaseHealth() {
    m_pPoints->DecreaseHealth();
    CheckPoints();
}

void CSpaceInvaders::onGameOver() {
    close();
}

