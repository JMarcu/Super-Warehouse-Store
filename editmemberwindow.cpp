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

/*******************************DATE COMBOBOX ALGORITHM HERE***************************/
void editMemberWindow::on_CB_Month_currentIndexChanged(int index)
{
    int leap = ui->CB_year->currentText().toInt(0,10) % 4;

    if(ui->CB_Month->currentIndex() == 1 || ui->CB_Month->currentIndex() == 3 ||
       ui->CB_Month->currentIndex() == 5 || ui->CB_Month->currentIndex() == 7 ||
       ui->CB_Month->currentIndex() == 8 || ui->CB_Month->currentIndex() == 10
       || ui->CB_Month->currentIndex() == 12)
    {
        if(ui->CB_Day->maxCount() < 32)
        {
            if(ui->CB_Day->maxCount() < 31)
            {
                if(ui->CB_Day->maxCount() < 30)
                {
                    ui->CB_Day->setMaxCount(32);
                    ui->CB_Day->addItem("29");
                    ui->CB_Day->addItem("30");
                    ui->CB_Day->addItem("31");
                }
                else
                {
                    ui->CB_Day->setMaxCount(32);
                    ui->CB_Day->addItem("30");
                    ui->CB_Day->addItem("31");
                }
            }
            else
            {
                ui->CB_Day->setMaxCount(32);
                ui->CB_Day->addItem("31");
            }
        }
    }
    else if(ui->CB_Month->currentIndex() == 2)
    {
        if(leap == 0 || ui->CB_year->currentIndex() == 1)
        {
           ui->CB_Day->setMaxCount(30);

        }
        else
        {
           ui->CB_Day->setMaxCount(29);
        }
    }
    else
    {
        ui->CB_Day->setMaxCount(31);
    }
}

void editMemberWindow::on_CB_year_currentIndexChanged(int index)
{
    int leapyear = ui->CB_year->currentText().toInt(0,10) % 4;

    if(ui->CB_Day->maxCount() < 32)
    {
        if(ui->CB_Day->maxCount() < 31)
        {
            if(ui->CB_Day->maxCount() < 30)
            {
                ui->CB_Day->setMaxCount(32);
                ui->CB_Day->addItem("29");
                ui->CB_Day->addItem("30");
                ui->CB_Day->addItem("31");
            }
            else
            {
                ui->CB_Day->setMaxCount(32);
                ui->CB_Day->addItem("30");
                ui->CB_Day->addItem("31");
            }
        }
        else
        {
            ui->CB_Day->setMaxCount(32);
            ui->CB_Day->addItem("31");
        }
    }

    if(ui->CB_Month->currentIndex() == 2)
    {
        if(ui->CB_year->currentIndex() == 1 && leapyear == 0)
        {
            ui->CB_Day->setMaxCount(30);
        }
        else
        {
            ui->CB_Day->setMaxCount(29);
        }
    }
}
/*************************************************************************************/
