#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "mainwindow.h"
#include "Database.h"

namespace Ui {
class AddItemWindow;
}

class AddItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief AddItemWindow
     * @param db
     * @param parent
     * - constructor
     */
    explicit AddItemWindow(Database *db, QWidget *parent = 0);
    ~AddItemWindow();

signals:
    /**
     * @brief ItemAdded
     *  - Sends signal of item added to database
     */
    void ItemAdded(QString, int);


private slots:
    /**
     * @brief on_pushButton_AddItem_clicked
     *  - sends signal of item added and closes window
     */
    void on_pushButton_AddItem_clicked();

    /**
     * @brief on_pushButton_ItemCancel_clicked
     * - closes window
     */
    void on_pushButton_ItemCancel_clicked();

private:
    Ui::AddItemWindow *ui;
    QString           itemName;
    int               itemAmount;
    double            itemPrice;
    Database *db;
};







#endif // ADDITEMWINDOW_H
