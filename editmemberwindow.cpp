#include "editmemberwindow.h"
#include "ui_editmemberwindow.h"
#include <QWidget>

editMemberWindow::editMemberWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editMemberWindow)
{
    ui->setupUi(this);
    this->db = db;
}

editMemberWindow::~editMemberWindow()
{
    delete ui;
}

void editMemberWindow::on_editMemberConform_accepted()
{
    memberName = ui->memberEditName->text();

    expirationDate.UpdateDate(ui->CB_Month->currentIndex(), ui->CB_Day->currentIndex(),
                          ui->CB_year->currentIndex());

    if(ui->comboBoxExecutive->currentIndex() == 0)
    {
        isExecutive = false;
    }
    else
    {
        isExecutive = true;
    }
    emit MemberEdit(memberName, this->memberID, expirationDate, isExecutive);

    /**********************
     * ADD TO DATABSE
     ************************/

    hide();
}

void editMemberWindow::on_editMemberConform_rejected()
{
    hide();
}

