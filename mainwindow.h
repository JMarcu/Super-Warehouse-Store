#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reportwindow.h"
#include <QTableView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

    void on_push_Report_clicked();

    void on_push_AddItem_clicked();

    void on_push_EditItem_clicked();

    void on_push_RemoveItem_clicked();

    void on_tableWidget_itemlist_cellClicked(int row, int column);

    void on_report_SetAuto_clicked();

    void on_report_SetManual_clicked();


    void on_push_AddMember_clicked();

    void on_push_EditMember_clicked();

    void on_push_RemoveMember_clicked();

    void on_push_ExpireSearch_clicked();

    void on_tableWidget_memberlist_cellClicked(int row, int column);






private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
