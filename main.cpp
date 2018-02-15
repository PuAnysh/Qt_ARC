#include <QApplication>
#include "mainwindow.h"
#include "test.h"
int main(int argc ,char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;
    w.show();
    Test test;
    test.gao();
    return a.exec();
}
