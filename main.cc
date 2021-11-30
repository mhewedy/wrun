/**
 *  Auther : Mohammed Hewedy 
 *  Email  : mohammed_a_hewedy@hotmail.com
 *  Date   : 21 October 2010
 *  Lincence: Waqf Public Licence
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
