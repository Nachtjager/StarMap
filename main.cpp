
#include <QApplication>
#include "screen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Screen screen;
    screen.show();
    return a.exec();
}
