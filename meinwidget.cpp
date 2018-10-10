#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include "meinWidget.h"
#include "zeichenFeld.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

meinWidget::meinWidget(QWidget* parent)
    : QWidget(parent) {

    //erstellen der vier Buttons
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

    //erstellen eines Zeichenfeldes
    meinZeichenFeld = new zeichenFeld;
    meinZeichenFeld->setFocusPolicy(Qt::StrongFocus);

    //erstellen des gridlayouts und belegen der einzelnen widgets
    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(starter, 0, 0);
    gridLayout->addWidget(saver, 1, 0);
    gridLayout->addWidget(loader, 2, 0);
    gridLayout->addWidget(close, 3, 0);
    gridLayout->addWidget(meinZeichenFeld, 0, 1, 5, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);
}

/*
 Die Methode start() startet das Spiel.
 Über eine boolean Abfrage wird die Beschriftung des Start-Buttons geändert.
 Danach kann über den gleichen Button das Spiel pausiert werden.
*/
void meinWidget::start(void){
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

// Die Methode saveFile() macht das Speichern eines Savegames möglich.
void meinWidget::saveFile(void){
    if (meinZeichenFeld->getPunkteStand() == 0){
        QMessageBox::warning(this, tr("Fehler"), tr("Du musst das Spiel erst starten!"), QMessageBox::Ok);
        return;
    }
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getSaveFileName(this,tr("Speichern als"), ".", tr("Savegame-File (*.savegame)"));


    if (fileName.isNull() == false){
        file.setFileName(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QMessageBox::warning(this, tr("Dateifehler"), tr("Folgende Datei kann nicht verwendet werden: ") + fileName, QMessageBox::Ok);
        }
        meinZeichenFeld->serialize(file);
        file.close();
        return;
    }
}

// Die Methode loadFile() macht das Laden eines Savegames möglich.
void meinWidget::loadFile(void){
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this, tr("Speichern als"), ".", tr("Savegame-File (*.savegame)"));
    if (fileName.isNull() == false){
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this, tr("Dateifehler"), tr("Folgende Datei kann nicht geöffnet werden: ") + fileName, QMessageBox::Ok);
        }
        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}
