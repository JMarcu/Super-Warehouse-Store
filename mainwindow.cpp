#include "mainwindow.h"
#include "ui_mainwindow.h"

/******************************************************************************************************
*    NOTICE:
*           Most of the definitions here are not fully implemented yet, and most requires a database
*           class object.  This file will be updated after tests with the GUI files.
*
******************************************************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget_memberlist->resizeColumnsToContents();

    ui->tableWidget_itemlist->resizeColumnsToContents();


}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_tableWidget_itemlist_cellClicked(int row, int column)
{
    switch(column)
    {
        case 1: break;

        case 2: break;

        case 3: break;
    }
}

void on_tableWidget_memberlist_cellClicked(int row, int column)
{
    switch(column)
    {
        case 1: break;

        case 2: break;

        case 3: break;

        case 4: break;
    }
}

void MainWindow::on_report_SetAuto_clicked()
{
    ui->report_SetManual->setCheckState(Qt::Unchecked);
}

void MainWindow::on_report_SetManual_clicked()
{
    ui->report_SetAuto->setCheckState(Qt::Unchecked);
}



void MainWindow::on_push_Report_clicked()
{
    reportWindow *i = new reportWindow(this);
    if(ui->report_SetAuto->checkState() == Qt::Checked)
    {
      i->show();
    }
}
