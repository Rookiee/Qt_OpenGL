#include <QApplication>
#include "nehewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    NeheWidget w;
    w.resize(400,300);
    w.show();
    return a.exec();
}
