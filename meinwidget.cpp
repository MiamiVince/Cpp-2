#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include "meinWidget.h"
#include "zeichenFeld.h"

meinWidget::meinWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *startPause = new QPushButton(tr("Start"));
    startPause->setFont(QFont("Times", 18, QFont::Bold));
    connect(startPause, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *save = new QPushButton(tr("Speichern"));
    save->setFont(QFont("Times", 18, QFont::Bold));
    connect(save, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *load = new QPushButton(tr("Laden"));
    load->setFont(QFont("Times", 18, QFont::Bold));
    connect(load, SIGNAL(clicked()), this, SLOT(loadFile()));

    zeichenFeld *meinZeichenFeld = new zeichenFeld;

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(startPause, 0, 0);
    gridLayout->addWidget(save, 1, 0);
    gridLayout->addWidget(load, 2, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 5, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}
