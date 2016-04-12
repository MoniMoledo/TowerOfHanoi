#include "hanoi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hanoi w;
    w.show();

    return a.exec();
}
