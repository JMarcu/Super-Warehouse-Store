#include "editmemberwindow.h"
#include "ui_editmemberwindow.h"

editMemberWindow::editMemberWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editMemberWindow)
{
    ui->setupUi(this);

    // Still need to figure out how to read if the item consists of regular member or executive
}

editMemberWindow::~editMemberWindow()
{
    delete ui;
}

void editMemberWindow::on_RegularCheck_edit_clicked()
{
    ui->ExecutiveCheck_edit->setCheckState(Qt::Unchecked);
}

void editMemberWindow::on_ExecutiveCheck_edit_clicked()
{
    ui->RegularCheck_edit->setCheckState(Qt::Unchecked);
}

void editMemberWindow::on_editMemberConform_accepted()
{
    if(ui->RegularCheck_edit->checkState() == Qt::Checked)
    {
        memberName = ui->memberEditName->inputMask();

        //memberID = ui->memberEditID->inputMask();

        memberType = "Regular";

        expMonth = ui->EditMonthBox->value();

        expDay = ui->EditDayBox->value();

        expYear = ui->EditYearBox->value();

        //regular.SetMember(memberName, memberID, expMonth, expDay, expYear);
    }
    else
    {
        memberName = ui->memberEditName->inputMask();

       // memberID = ui->memberEditID->inputMask();

        memberType = "Executive";

        expMonth = ui->EditMonthBox->value();

        expDay = ui->EditDayBox->value();

        expYear = ui->EditYearBox->value();

      //  regular.SetMember(memberName, memberID, expMonth, expDay, expYear);
    }

    hide();
}

void editMemberWindow::on_editMemberConform_rejected()
{
    hide();
}

void editMemberWindow::on_memberEditID_returnPressed()
{
//    if((ui->memberEditID->inputMash() != IDValidator.Acceptable &&
//        ui->memberEditID ->inputMask() != IDValidator.Intermediate) &&
//        (db->GetMember != NULL))
    {
        ui->IdErrorLabel->setText("Invalid ID Value! \n"
                                  "(No negative values, no characters,"
                                  " must be less than 6 digits)");

        // keep hiding the "OK" Button
    }
   // else if(db->GetMember = NULL)
    {
        ui->IdErrorLabel->setText("The number ID you inputed alredy exists!\n"
                                  "Please try again");
    }
//    else
//    {
//        ui->IdErrorLabel->setText("ID number is valid.");

//        // Show the "OK Button"
//    }
}
