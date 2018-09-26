#ifndef MEINWIDGET_H
#define MEINWIDGET_H

#include "zeichenFeld.h"
#include <QWidget>


class meinWidget : public QWidget
{
    Q_OBJECT
public:
    meinWidget(QWidget *parent = 0);

private:
    zeichenFeld *meinZeichenFeld;

private slots:
    void start(void);
    void stop(void);

};
#endif // MEINWIDGET_H
