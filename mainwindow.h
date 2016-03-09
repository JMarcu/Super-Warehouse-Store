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

/*-------Buttons that sort the list of items in the store's inventory--------*/
    void on_sort_ItemName_clicked();    // Sorts list my name

    void on_sort_ItemAmount_clicked();  // Sorts list by amount

    void on_sort_ItemPrice_clicked();   // Sorts list by price
/*---------------------------------------------------------------------------*/

    

    void on_push_AddItem_clicked();

    void on_push_EditItem_clicked();

    void on_push_RemoveItem_clicked();

    void on_report_SetAuto_stateChanged(int arg1);

    void on_report_SetManual_stateChanged(int arg1);
    



    void on_sort_memberName_clicked();

    void on_sort_MemberID_clicked();

    void on_sort_memberExperation_clicked();

    void on_sort_memberTotal_clicked();

    void on_push_AddMember_clicked();

    void on_push_EditMember_clicked();

    void on_push_RemoveMember_clicked();

    void on_push_ExpireSearch_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
