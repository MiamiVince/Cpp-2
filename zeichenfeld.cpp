#include <QtGui>
#include <QPainter>

#include "zeichenFeld.h"

zeichenFeld::zeichenFeld(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

void zeichenFeld::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
}





