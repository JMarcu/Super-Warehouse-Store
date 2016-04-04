#include "editmemberwindow.h"
#include "ui_editmemberwindow.h"
#include <QWidget>
#include "errorwindow.h"

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
    memberID = ui->memberEditName->text().toInt(0,10);

    bool valid = false;

    int year;

    switch(ui->CB_year->currentIndex())
    {
        case 1 : year = 2015;
            break;
        case 2 : year = 2016;
            break;
        case 3 : year = 2017;
            break;
        case 4 : year = 2018;
            break;
        case 5 : year = 2019;
            break;
        case 6 : year = 2020;
            break;
        case 7 : year = 2021;
            break;
        case 8 : year = 2022;
            break;
        case 9 : year = 2023;
            break;
        case 10: year = 2024;
            break;
        case 11 : year = 2025;
            break;
        case 12 : year = 2026;
            break;
    }

    expirationDate.UpdateDate(ui->CB_Month->currentIndex(), ui->CB_Day->currentIndex(),
                          year);

    std::list<Member> *memList = db->GetAllMembers();
    std::list<Member>::const_iterator member = memList->begin();

    while(member != memList->end() && valid != true)
    {
        if(member->GetID() == memberID)
        {
            valid = true;
        }
        else
        {
            member++;
        }
    }

    if(valid == false)
    {
        ErrorWindow *error = new ErrorWindow(1);
        error->show();
    }
    else
    {
        if(ui->comboBoxExecutive->currentIndex() == 0)
        {
            isExecutive = false;
        }
        else
        {
            isExecutive = true;
        }
        emit MemberEdit(member->GetName(), memberID, expirationDate, isExecutive, member->GetTotalSpent());

        db->UpdateMember(Member(member->GetName(), memberID, member->GetTotalSpent(), expirationDate, isExecutive));

        hide();
    }


    delete memList;
}

void editMemberWindow::on_editMemberConform_rejected()
{
    hide();
}

