#include "meinWidget.h"
// Qt5 add:
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    meinWidget widget;
    widget.setGeometry(100, 100, 500, 500);
    widget.show();
    return app.exec();
}