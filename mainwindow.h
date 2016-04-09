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
#include "errorwindow.h"
#include "searchstring.h"
#include "Member.h"
#include "adddate.h"
#include "removememberitem.h"

namespace Ui {
class MainWindow;
}

enum errorMessage
{
    NAME_MEM,
    ID,
    NAME_ITEM,
    ITEM_NF,
    MEM_NF,
    DATE,
    MEM_SALE,
    EXP
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param db
     * @param parent
     */
    explicit MainWindow(Database *db, QWidget *parent = 0 );
    ~MainWindow();
signals:
    /**
     * @brief SortAndEditRow
     * @param row
     * @param column
     */
    void SortAndEditRow(int row, int column);
    /**
     * @brief CellEditOrRemove
     * @param row
     */
    void CellEditOrRemove(int row);
    /**
     * @brief AddMember
     */
    void AddMember(QString, int, Date, bool);

public slots:
    /**
     * @brief AddItemToItemsTable
     * @param name
     * @param price
     */
    void AddItemToItemsTable(QString name, double price);
    /**
     * @brief AddMemberToTable
     * @param name
     * @param id
     * @param expiration
     * @param isExecutive
     * @param totalSpent
     */
    void AddMemberToTable(QString name, int id, Date expiration, bool isExecutive , double totalSpent);

    /**
     * @brief AddDailySalesReport
     * @param dateIn
     */
    void AddDailySalesReport(Date dateIn);

    /**
     * @brief ExpiredMembershipsReport
     * @param dateIn
     */
    void ExpiredMembershipsReport(Date dateIn);

    /**
     * @brief PopulateMembers
     */
    void PopulateMembers();

    /**
     * @brief PopulateItems
     */
    void PopulateItems();

    /**
     * @brief AddSearchedItem
     * @param name
     */
    void AddSearchedItem(QString name);

    /**
     * @brief ClearTable
     * @param table
     */
    void ClearTable(QTableWidget *table);

    /**
     * @brief AddMemberPurchaseString
     * @param name
     */
    void AddMemberPurchaseString(QString name);

    /**
     * @brief AddMemberPurchaseInt
     * @param id
     */
    void AddMemberPurchaseInt(int id);

private slots:
    /**
     * @brief on_pushButtonAdd_clicked
     */
    void on_pushButtonAdd_clicked();

    /**
     * @brief on_pushButton_MemberAdd_clicked
     */
    void on_pushButton_MemberAdd_clicked();

    /**
     * @brief on_pushButtonEdit_clicked
     */
    void on_pushButtonEdit_clicked();

    /**
     * @brief on_pushButton_MemberEdit_clicked
     */
    void on_pushButton_MemberEdit_clicked();

    /**
     * @brief on_pushButton_MemberRemove_clicked
     */
    void on_pushButton_MemberRemove_clicked();

    /**
     * @brief on_ViewMembers_tabBarClicked
     * @param index
     */
    void on_ViewMembers_tabBarClicked(int index);

    /**
     * @brief on_SalesReport_Button_clicked
     */
    void on_SalesReport_Button_clicked();

    /**
     * @brief on_Expire_Button_clicked
     */
    void on_Expire_Button_clicked();

    /**
     * @brief on_Convert_Button_clicked
     */
    void on_Convert_Button_clicked();

    /**
     * @brief on_TotalPurchases_Button_clicked
     */
    void on_TotalPurchases_Button_clicked();

    /**
     * @brief on_ItemsSoldQuantity_Button_clicked
     */
    void on_ItemsSoldQuantity_Button_clicked();

    /**
     * @brief on_Rebates_Button_clicked
     */
    void on_Rebates_Button_clicked();

    /**
     * @brief on_ItemsSoldName_Button_clicked
     */
    void on_ItemsSoldName_Button_clicked();

    /**
     * @brief on_MemberPurchases_Button_clicked
     */
    void on_MemberPurchases_Button_clicked();

    /**
     * @brief on_pushButtonRemove_clicked
     */
    void on_pushButtonRemove_clicked();

private:
    Ui::MainWindow *ui;
    int rowI;
    int rowM;
    int rowR;
    int rowS;
    int colR;
    int colS;
    Database *db;
};

#endif // MAINWINDOW_H
