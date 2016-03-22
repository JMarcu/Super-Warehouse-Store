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

    expirationDate.UpdateDate(ui->month->text().toInt(0,10), ui->day->text().toInt(0,10),
                          ui->year->text().toInt(0,10));

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

