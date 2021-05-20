#include "myqtclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyQtClass w;
    w.show();
    return a.exec();
}
