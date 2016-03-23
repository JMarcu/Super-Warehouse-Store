#include "editmemberwindow.h"
#include "ui_editmemberwindow.h"
#include <QWidget>

editMemberWindow::editMemberWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editMemberWindow)
{
    ui->setupUi(this);
}

editMemberWindow::~editMemberWindow()
{
    delete ui;
}

void editMemberWindow::on_editMemberConform_accepted()
{
    memberName = ui->memberEditName->text();

    expirationDate.UpdateDate(ui->spinBox_month->value(), ui->spinBox_day->value(),
                              ui->spinBox_year->value());

    if(ui->comboBoxExecutive->currentIndex() == 0)
    {
        isExecutive = false;
    }
    else
    {
        isExecutive = true;
    }
    emit MemberEdit(memberName, this->memberID, expirationDate, isExecutive);

    hide();
}

void editMemberWindow::on_editMemberConform_rejected()
{
    hide();
}

void editMemberWindow::on_spinBox_month_valueChanged(int arg1)
{
    if(ui->spinBox_month == 1 || ui->spinBox_month == 3 || ui->spinBox_month == 5
       || ui->spinBox_month == 7 || ui->spinBox_month == 8 || ui->spinBox_month == 10 ||
       ui->spinBox_month == 12)
    {
        ui->spinBox_day->setMaximum(31);
    }
    else
    {
        if(ui->spinBox_month == 2)
        {
            ui->spinBox_day->setMaximum(29);
        }
        else
        {
            ui->spinBox_day->setMaximum(30);
        }
    }
}

void editMemberWindow::on_spinBox_year_valueChanged(int arg1)
{
    int leapCheck;

    leapCheck = ui->spinBox_year->value() % 4;

    if(leapCheck = 0)
    {
        if(ui->spinBox_month->value() == 2)
        {
            ui->spinBox_day->setMaximum(30);
        }
    }
    else
    {
        if(ui->spinBox_month->value() == 2)
        {
            ui->spinBox_day->setMaximum(29);
        }
    }
}
