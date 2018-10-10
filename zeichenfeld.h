#ifndef ZEICHENFELD_H
#define ZEICHENFELD_H

#include <QWidget>
#include <QTimer>
#include <QFile>



class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);
    ~zeichenFeld();

    void start(void) { timer->start(20); increment = 1; };
    void stop(void) { timer->stop(); increment = 0; };
    void serialize(QFile &file);
    void deserialize(QFile &file);
    int getPunkteStand() { return punkteStand; };



private:
    int x;
    QTimer* timer;
    int punkteStand;
    int increment;
    int lastY;
    int randX;
    int randC;
    int lastV;




protected:
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent* event);

};

#endif // ZEICHENFELD_H
