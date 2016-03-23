#include "addmemberwindow.h"
#include "ui_addmemberwindow.h"

AddMemberWindow::AddMemberWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddMemberWindow)
{
    ui->setupUi(this);

}

AddMemberWindow::~AddMemberWindow()
{
    delete ui;
}

void AddMemberWindow::on_pushButton_MemberAdd_clicked()
{
    name = ui->lineEdit_Name->text();

    id = ui->lineEdit_ID->text().toInt(0,10);

    expiration.UpdateDate(ui->spinBox_month->value(), ui->spinBox_day->value(),
                          ui->spinBox_year->value());

    if(ui->comboBox_isExecutive->currentIndex() == 0)
    {
        isExecutive = false;
    }
    else
    {
        isExecutive = true;
    }

    emit AddMember(name,id,expiration,isExecutive);
    //db->AddMember(memberdata...)
    hide();
}

void AddMemberWindow::on_pushButton_MemberCancel_clicked()
{
    hide();
}

void AddMemberWindow::on_spinBox_month_valueChanged(int arg1)
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

void AddMemberWindow::on_spinBox_year_valueChanged(int arg1)
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
