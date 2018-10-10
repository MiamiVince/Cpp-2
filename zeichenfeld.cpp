#include <QtGui>
#include <QPainter>
#include "zeichenFeld.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

// Das Zeichenfeld erhält seine Farbe und Größe.
// wichtige Variabeln erhalten ihren Startwert und der Timer wird erstellt.
zeichenFeld::zeichenFeld(QWidget* parent)
    : QWidget(parent){
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
    setFixedSize(600, 500);
    x = 273;
    punkteStand = 0;
    increment = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

zeichenFeld::~zeichenFeld(){}

void zeichenFeld::paintEvent(QPaintEvent*){

    // Zeichnen des Avatars
    QPainter player;
    player.begin(this);
    player.setBrush(Qt::BDiagPattern);
    player.drawRect(x, 440, 55, 55);
    player.end();

    // Zeichnen des Punktestandes
    QPainter score;
    score.begin(this);
    score.setFont(QFont("Times", 20, QFont::Bold));
    score.drawText(20, 30, "Punkte: " + QString::number(punkteStand));
    // Bei jedem erneuten Zeichenvorgang wird der Punktestand um eins erhöht, sofern das Spiel läuft.
    if (increment == 1){
        punkteStand++;
    }
    score.end();

    //Zeichnen der drei Leben
    QPainter lifes;
    lifes.begin(this);
    lifes.setBrush(QBrush(Qt::black));
    lifes.drawEllipse(480, 15, 25, 25);
    lifes.drawEllipse(520, 15, 25, 25);
    lifes.drawEllipse(560, 15, 25, 25);
    lifes.end();

    // Zeichnen der herab fallenden Kreise
    QPainter kreise;
    int y;
    kreise.begin(this);
    y = lastY - 46;
    kreise.setBrush(QBrush(Qt::gray));
    kreise.drawEllipse(randX,y,45,45);
    if (increment){
        lastY += 8;
        if (lastY > 551){
            lastY = 0;
            randX = rand() % 556;
        }
    }
    kreise.end();

    // Zeichnen der herab fallenden Quadrate
    QPainter quadrate;
    int v;
    quadrate.begin(this);
    v = lastV - 46;
    quadrate.setBrush(QBrush(Qt::darkGray));
    quadrate.drawRect(randC,v,45,45);

    if (increment){
        lastV += 6;
        if (lastV > 551){
            lastV = 0;
            randC = rand() % 556;
        }
    }
    quadrate.end();
}

// Das keyPressEvent ermöglicht das Bewegen des Avatars.
void zeichenFeld::keyPressEvent(QKeyEvent* event)
{
    if (increment == 1){
        if (event->key() == Qt::Key_Left){
            if (x > 0)
                x -= 10;
        }
        if (event->key() == Qt::Key_Right){
            if (x < 545)
                x += 10;
        }
    }
}

/*
    Die Methode serialize() erhält Informationen, die zum Speichern des Spielstandes wichtig sind.
    Das sind Punktestand, X und Y Position der herabfallenden Objekte und die Position des Avatars.
*/
void zeichenFeld::serialize(QFile &file){
    QTextStream out(&file);
    out << "Savegame" << endl;
    out << "x " << x << " " << punkteStand << " " << lastY << " " << lastV << " " << randX << " " << randC << endl;
}

/*
    Die Methode deserialize() liefert Informationen, die zum Laden des gespeicherten Spielstandes wichtig sind.
    Das sind Punktestand, X und Y Position der herabfallenden Objekte und die Position des Avatars.
    Hier ist mir ein Fehler unterlaufen, den ich nicht lösen konnte. Bei jedem Ladevorgang eines
    Savegames wird ein Objektfehler ausgegeben. Der Spielstand wird allerdings trotzdem richtig geladen.
    Ich habe die Abfrage if (c != 'x') mit if (c == 'x') getestet. Der Fehler wird dann wieder jedes
    mal ausgegeben.
*/
void zeichenFeld::deserialize(QFile &file){
char c;
QString test;
    QTextStream in(&file);
    in >> test;
    if (test != "Savegame"){
        QMessageBox::warning(this, tr("Formatfehler"),tr("Das ist keine Zeichnungsdatei!"),QMessageBox::Ok);
        return;
    }
    in >> c;
    while (in.status() == QTextStream::Ok){
        in >> c;
        if (in.status() == QTextStream::ReadPastEnd) break;
        if (c != 'x'){
            QMessageBox::warning(this, tr("Objektfehler"),tr("Folgender Objekttyp ist unbekannt: ") + c,QMessageBox::Ok);
            return;
        }
        in >> x >> punkteStand >> lastY >> lastV >> randX >> randC;
    }
    update();
}
