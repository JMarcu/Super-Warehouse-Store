#include "mainwindow.h"
#include <QApplication>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database *db = new Database("WarehouseDB.db3");

    qDebug() << db->GetAllMembers()->size();
//    MainWindow w(db);
//    w.show();

    return a.exec();
}
