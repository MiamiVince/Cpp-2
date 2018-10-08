#include <QtGui>
#include <QPainter>
#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget* parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
    setFixedSize(600, 500);
    x = 273;
    punkteStand = 0;
    increment = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

zeichenFeld::~zeichenFeld()
{

}

void zeichenFeld::paintEvent(QPaintEvent*)
{

    QPainter player;
    player.begin(this);
    player.setBrush(Qt::BDiagPattern);
    player.drawRect(x, 440, 55, 55);
    player.end();

    QPainter score;
    score.begin(this);
    score.setFont(QFont("Times", 20, QFont::Bold));
    score.drawText(20, 30, "Punkte: " + QString::number(punkteStand));
    if (increment == 1)
        punkteStand++;
    score.end();

    QPainter lifes;
    lifes.begin(this);
    lifes.setBrush(QBrush(Qt::black));
    lifes.drawEllipse(480, 15, 25, 25);
    lifes.drawEllipse(520, 15, 25, 25);
    lifes.drawEllipse(560, 15, 25, 25);
    lifes.end();


}

void zeichenFeld::keyPressEvent(QKeyEvent* event)
{
    if (increment == 1) {
        if (event->key() == Qt::Key_Left) {
            if (x > 0)
                x -= 10;
            }
        if (event->key() == Qt::Key_Right) {
            if (x < 545)
                x += 10;
            }
    }
}




