#include <QApplication>
#include "nehewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NeheWidget w(0, false);
    w.show();
    return a.exec();
}
