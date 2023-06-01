#include <QApplication>
#include <QScreen>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "spaceinvaders.h"

int main(int argc, char *argv[]) {
    //    QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    QApplication a(argc, argv);

    CSpaceInvaders* pGame = new CSpaceInvaders(/*QSize(1920,1080)*/qApp->screens()[0]->size());
    pGame->showFullScreen();
    pGame->Run();

    auto* player = new QMediaPlayer;
    auto* audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("qrc:/Resources/music.mp3"));
    audioOutput->setVolume(100);
    player->setLoops(QMediaPlayer::Infinite);
    player->play();

    return a.exec();
}
