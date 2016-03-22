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

    expiration.UpdateDate(ui->Month_Edit->text().toInt(0,10), ui->Day_Edit->text().toInt(0,10),
                          ui->Year_Edit->text().toInt(0,10));

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
