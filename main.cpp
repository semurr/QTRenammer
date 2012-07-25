#include <QtGui/QApplication>
#include "mainwindow.h"
#include "filelist.h"

int main(int argc, char *argv[])
{
    //create gui application
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
