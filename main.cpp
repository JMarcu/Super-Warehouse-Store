#include "mainwindow.h"
#include <QApplication>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database *db = new Database("WarehouseDB.db3");
    MainWindow w(db);
    w.show();

    return a.exec();
}
