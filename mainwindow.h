#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "additemwindow.h"
#include "addmemberwindow.h"
#include "edititemwindow.h"
#include <QTableView>
#include <QTableWidgetItem>
#include <QDebug>
#include "date.h"
#include"Database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Database *db, QWidget *parent = 0 );
    ~MainWindow();
signals:
        void SortAndEditRow(int row, int column);
public slots:
    void AddItemToItemsTable(QString name, int quantity, double price);
    void SortColumn(int column);
    void AddMemberToTable(QString name, int id, Date expiration, bool isExecutive );

private slots:

    void on_pushButtonAdd_clicked();

    void on_tableWidgetItem_cellClicked(int row, int column);

    void on_pushButton_MemberAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_ViewReports_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    int rowI;
    int rowM;

    Database * db;
};

#endif // MAINWINDOW_H
