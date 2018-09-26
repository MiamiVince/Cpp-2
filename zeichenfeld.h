#ifndef ZEICHENFELD_H
#define ZEICHENFELD_H


#include <QWidget>
#include <QTimer>

class zeichenFeld : public QWidget
{
public:
    zeichenFeld(QWidget *parent = 0);

    void start(void) { timer->start(10); increment=1; };
    void stop(void) { timer->stop(); increment=0; };

private:
    int x;
    QTimer* timer;
    int punkteStand;
    int increment;

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent* event);

};

#endif // ZEICHENFELD_H
