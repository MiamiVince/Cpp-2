#include "meinWidget.h"
#include <QApplication>

int main(int argc, char *argv[]){

/*
    Clemens Haberl
    Matrikelnummer: 7324637
    C++ Semesterarbeit Teil 2 SoSe 2018
    BM3: Softwaretechnologie
    Prof. Dr. Eide
    10.10.2018
*/
    QApplication app(argc, argv);
    meinWidget widget;
    widget.setGeometry(100, 100, 500, 500);
    widget.show();
    return app.exec();
}
