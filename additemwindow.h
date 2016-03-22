#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "mainwindow.h"

namespace Ui {
class AddItemWindow;
}

class AddItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddItemWindow(QWidget *parent = 0);
    ~AddItemWindow();

signals:
    void ItemAdded(QString, int, double);


private slots:
    void on_pushButton_AddItem_clicked();

    void on_pushButton_ItemCancel_clicked();

private:
    Ui::AddItemWindow *ui;
    QString           itemName;
    int               itemAmount;
    double            itemPrice;
};







#endif // ADDITEMWINDOW_H
