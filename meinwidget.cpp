#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include "meinWidget.h"
#include "zeichenFeld.h"

meinWidget::meinWidget(QWidget* parent)
    : QWidget(parent)
{

    starter->setFont(QFont("Times", 18, QFont::Bold));
    connect(starter, SIGNAL(clicked()), this, SLOT(start()));

    QPushButton *close = new QPushButton(tr("Close"));
    close->setFont(QFont("Times", 18, QFont::Bold));
    connect(close, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *saver = new QPushButton(tr("Speichern"));
    saver->setFont(QFont("Times", 18, QFont::Bold));
    connect(saver, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *loader = new QPushButton(tr("Laden"));
    loader->setFont(QFont("Times", 18, QFont::Bold));
    connect(loader, SIGNAL(clicked()), this, SLOT(loadFile()));

    meinZeichenFeld = new zeichenFeld;
    meinZeichenFeld->setFocusPolicy(Qt::StrongFocus);

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(starter, 0, 0);
    gridLayout->addWidget(saver, 1, 0);
    gridLayout->addWidget(loader, 2, 0);
    gridLayout->addWidget(close, 3, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 5, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}

void meinWidget::start(void)
{
    if(startPause == true){
        meinZeichenFeld->start();
        startPause = false;
        starter->setText("Stop");
    }
    else if (startPause == false){
        meinZeichenFeld->stop();
        startPause = true;
        starter->setText("Start");
    }
}
void meinWidget::stop(void){}
