#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include "meinWidget.h"
#include "zeichenFeld.h"

meinWidget::meinWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *start = new QPushButton(tr("Start"));
    start->setFont(QFont("Times", 18, QFont::Bold));
    connect(start, SIGNAL(clicked()), qApp, SLOT(start()));

    QPushButton *stop = new QPushButton(tr("Close"));
    stop->setFont(QFont("Times", 18, QFont::Bold));
    connect(stop, SIGNAL(clicked()), this, SLOT(quit()));

    QPushButton *save = new QPushButton(tr("Speichern"));
    save->setFont(QFont("Times", 18, QFont::Bold));
    connect(save, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *load = new QPushButton(tr("Laden"));
    load->setFont(QFont("Times", 18, QFont::Bold));
    connect(load, SIGNAL(clicked()), this, SLOT(loadFile()));

    zeichenFeld *meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(start, 0, 0);
    gridLayout->addWidget(stop, 1, 0);
    gridLayout->addWidget(save, 2, 0);
    gridLayout->addWidget(load, 3, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 5, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}

void meinWidget::start(void)
{
    meinZeichenFeld->start();
}

void meinWidget::stop(void)
{
    meinZeichenFeld->stop();
}
