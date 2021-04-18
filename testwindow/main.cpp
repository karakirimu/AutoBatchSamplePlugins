#include "testwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestWindow w;
    w.preloadPlugin(a.arguments());
    w.show();
    return a.exec();
}
