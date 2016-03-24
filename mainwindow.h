#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "additemwindow.h"
#include "addmemberwindow.h"
#include "edititemwindow.h"
#include "editmemberwindow.h"
#include <QTableView>
#include <QTableWidgetItem>
#include <QDebug>
#include "date.h"

#include "Member.h"
#include "adddate.h"

namespace Ui {
class MainWindow;
}

enum errorMessage
{
    NAME_MEM,
    ID,
    NAME_ITEM
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Database *db, QWidget *parent = 0 );
    ~MainWindow();
signals:
        void SortAndEditRow(int row, int column);
        void CellEditOrRemove(int row);
        void AddMember(QString, int, Date, bool);

public slots:
    void AddItemToItemsTable(QString name, double price);
    void AddMemberToTable(QString name, int id, Date expiration, bool isExecutive );
    void RemoveMember(int rowRemove);
    void AddDailySalesReport(Date dateIn);
    void ExpiredMembershipsReport(Date dateIn);
    void PopulateMembers();
    void PopulateItems();

private slots:

    void on_pushButtonAdd_clicked();

    void on_tableWidgetItem_cellClicked(int row, int column);

    void on_pushButton_MemberAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButton_MemberEdit_clicked();

    void on_tableWidgetMembers_cellClicked(int row, int column);

    void on_pushButton_MemberRemove_clicked();

    void on_ViewMembers_tabBarClicked(int index);

    void on_SalesReport_Button_clicked();

    void on_Expire_Button_clicked();

    void on_Convert_Button_clicked();

private:
    Ui::MainWindow *ui;
    int rowI;
    int rowM;
    int rowR;
    int rowS;
    Database *db;
};

#endif // MAINWINDOW_H
