#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sort_ItemName_clicked()
{

}

void MainWindow::on_sort_ItemAmount_clicked()
{

}

void MainWindow::on_sort_ItemPrice_clicked()
{

}

void MainWindow::on_push_Report_clicked()
{

}

void MainWindow::on_push_AddItem_clicked()
{

}

void MainWindow::on_push_EditItem_clicked()
{

}

void MainWindow::on_push_RemoveItem_clicked()
{

}

void MainWindow::on_report_SetAuto_stateChanged(int arg1)
{

}

void MainWindow::on_report_SetManual_stateChanged(int arg1)
{

}




void MainWindow::on_sort_memberName_clicked()
{

}


void MainWindow::on_sort_MemberID_clicked()
{

}

void MainWindow::on_sort_memberExperation_clicked()
{

}

void MainWindow::on_sort_memberTotal_clicked()
{

}

void MainWindow::on_push_AddMember_clicked()
{

}

void MainWindow::on_push_EditMember_clicked()
{

}

void MainWindow::on_push_RemoveMember_clicked()
{

}

void MainWindow::on_push_ExpireSearch_clicked()
{

}
