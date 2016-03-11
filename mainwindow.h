#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reportwindow.h"
#include <QTableView>


namespace Ui {
class MainWindow;
}

/***********************************************************************
 * MainWindow
 *    
 *    This class acts as the main GUI window of the program.
 ***********************************************************************/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

    void on_push_Report_clicked();          // Button that activates an item report (opens a sub window)

    void on_push_AddItem_clicked();         // Button that opens a menu to add an item

    void on_push_EditItem_clicked();        // Button that opens a menu to edit an item clicked on by the user in a list.

    void on_push_RemoveItem_clicked();      // Button that removes an item from the list.

    void on_tableWidget_itemlist_cellClicked(int row, int column);  // Column cells that sorts the items if clicked on.

    void on_report_SetAuto_clicked();       // A check box button that gets set if the user wants
                                            // to automatically report item purchases

    void on_report_SetManual_clicked();     // A check box button that gets set if the user wants to perform item purchase report by
                                            // hand

    void on_push_AddMember_clicked();       // Button that brings a sub menu to add a club member

    void on_push_EditMember_clicked();      // Button that brings a menu to edit a club member clicked on by the user

    void on_push_RemoveMember_clicked();    // Button that removes a club member cliecked on by the user

    void on_push_ExpireSearch_clicked();    // Button that brings a sub menu that promts the user which month
                                            // club member's membership expires

    void on_tableWidget_memberlist_cellClicked(int row, int column);    // Clickable column labels that sort members if clicked by user.






private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
