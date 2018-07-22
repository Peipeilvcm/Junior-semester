#include "mainwindow.h"
#include <QApplication>
#include "globalinfo.h"

GlobalInfo* GlobalInfo::s_instance = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
