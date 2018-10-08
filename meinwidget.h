#ifndef MEINWIDGET_H
#define MEINWIDGET_H

#include "zeichenFeld.h"
#include <QWidget>
#include <QPushButton>


class meinWidget : public QWidget
{
    Q_OBJECT
public:
    meinWidget(QWidget *parent = 0);

private:
    zeichenFeld *meinZeichenFeld;
    QPushButton *starter = new QPushButton(tr("Start"));
    bool startPause = true;

private slots:
    void start(void);
    void stop(void);


};
#endif // MEINWIDGET_H
