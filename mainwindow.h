#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


// Methods that are executed when "clicked on" by the user using the user interface

private slots:

// Items/Inventory

/*-------Buttons that sort the list of items in the store's inventory--------*/
    void on_sort_ItemName_clicked();    // Sorts list my name

    void on_sort_ItemAmount_clicked();  // Sorts list by amount

    void on_sort_ItemPrice_clicked();   // Sorts list by price
/*---------------------------------------------------------------------------*/

    
    void on_push_AddItem_clicked();     // Brings a submenu to create an item and store in the list.

    void on_push_EditItem_clicked();    // Edits any item selected by the user.

    void on_push_RemoveItem_clicked();  // Removes any item selected by the user.

/*--------------------Daily sales report UI Functionality---------------------*/
    void on_report_SetAuto_stateChanged(int arg1);  // A check box if the user wants to initialize daily report by file

    void on_report_SetManual_stateChanged(int arg1); // A check box if the user wants to initialize daily report by hand
    
    void on_push_Report_clicked();  // Button that activates the daily sales.
/*----------------------------------------------------------------------------*/

// Members

/*------------------Buttons that sort the club member list--------------------*/
    void on_sort_memberName_clicked();      // Sorts list by name

    void on_sort_MemberID_clicked();        // Sorts list by member ID

    void on_sort_memberExperation_clicked(); // Sorts list by experation date

    void on_sort_memberTotal_clicked();     // Sorts list by total money spent
/*----------------------------------------------------------------------------*/

    void on_push_AddMember_clicked();       // Button that opens a submenu to add a member

    void on_push_EditMember_clicked();      // Button that opens a submenu to edit a member once selected

    void on_push_RemoveMember_clicked();    // Button that removes a member once selected

    void on_push_ExpireSearch_clicked();    // Brings submenu for the user to input experation date by month, day, and/or year
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
