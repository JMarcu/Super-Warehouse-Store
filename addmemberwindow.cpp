#include "addmemberwindow.h"
#include "ui_addmemberwindow.h"
#include "errorwindow.h"

AddMemberWindow::AddMemberWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddMemberWindow)
{
    ui->setupUi(this);
    this->db = db;

    ui->cb_month->setMaxVisibleItems(7);

    ui->cb_day->setMaxVisibleItems(7);

    ui->cb_year->setMaxVisibleItems(7);
}

AddMemberWindow::~AddMemberWindow()
{
    delete ui;
}

void AddMemberWindow::on_pushButton_MemberAdd_clicked()
{
    bool valid;
    valid = true;

    int year;

    switch(ui->cb_year->currentIndex())
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

        name = ui->lineEdit_Name->text();

        id = ui->lineEdit_ID->text().toInt(0,10);

        expiration.UpdateDate(ui->cb_month->currentIndex(), ui->cb_day->currentIndex(),
                              year);

        if(ui->comboBox_isExecutive->currentIndex() == 0)
        {
            isExecutive = false;
        }
        else
        {
            isExecutive = true;
        }


        std::list<Member> *list = db->GetAllMembers();
        std::list<Member>::const_iterator members = list->begin();

        while(members != list->end())
        {
            if(id == members->GetID())
            {
                ErrorWindow *error = new ErrorWindow(1);
                error->show();
                valid = false;
            }

            if(name == members->GetName())
            {
                ErrorWindow *error = new ErrorWindow(0);
                error->show();
                valid = false;
            }

            members++;
        }


        if(valid == true)
        {
            emit AddMember(name,id,expiration,isExecutive);

            db->AddMember(Member(name, id, 0, expiration, isExecutive));
            hide();
        }

}

void AddMemberWindow::on_pushButton_MemberCancel_clicked()
{
    hide();
}

/*******************************DATE COMBOBOX ALGORITHM HERE***************************/
void AddMemberWindow::on_cb_month_currentIndexChanged(int index)
{
    int leap = ui->cb_year->currentText().toInt(0,10) % 4;

    if(ui->cb_month->currentIndex() == 1 || ui->cb_month->currentIndex() == 3 ||
       ui->cb_month->currentIndex() == 5 || ui->cb_month->currentIndex() == 7 ||
       ui->cb_month->currentIndex() == 8 || ui->cb_month->currentIndex() == 10
       || ui->cb_month->currentIndex() == 12)
    {
        if(ui->cb_day->maxCount() < 32)
        {
            if(ui->cb_day->maxCount() < 31)
            {
                if(ui->cb_day->maxCount() <= 30)
                {
                    ui->cb_day->setMaxCount(32);
                    ui->cb_day->addItem("29");
                    ui->cb_day->addItem("30");
                    ui->cb_day->addItem("31");
                }
                else
                {
                    ui->cb_day->setMaxCount(32);
                    ui->cb_day->addItem("30");
                    ui->cb_day->addItem("31");
                }
            }
            else
            {
                ui->cb_day->setMaxCount(32);
                ui->cb_day->addItem("31");
            }
        }
    }
    else if(ui->cb_month->currentIndex() == 2)
    {
        if(leap == 0)
        {
           ui->cb_day->setMaxCount(30);
        }
        else
        {
           ui->cb_day->setMaxCount(29);
        }
    }
    else
    {
        ui->cb_day->setMaxCount(31);
    }
}

void AddMemberWindow::on_cb_year_currentIndexChanged(int index)
{
    int leapyear = ui->cb_year->currentText().toInt(0,10) % 4;

    if(ui->cb_month->currentIndex() == 1 || ui->cb_month->currentIndex() == 3 ||
       ui->cb_month->currentIndex() == 5 || ui->cb_month->currentIndex() == 7 ||
       ui->cb_month->currentIndex() == 8 || ui->cb_month->currentIndex() == 10
       || ui->cb_month->currentIndex() == 12)
    {
        if(ui->cb_day->maxCount() < 32)
        {
            if(ui->cb_day->maxCount() < 31)
            {
                if(ui->cb_day->maxCount() <= 30)
                {
                    ui->cb_day->setMaxCount(32);
                    ui->cb_day->addItem("29");
                    ui->cb_day->addItem("30");
                    ui->cb_day->addItem("31");
                }
                else
                {
                    ui->cb_day->setMaxCount(32);
                    ui->cb_day->addItem("30");
                    ui->cb_day->addItem("31");
                }
            }
            else
            {
                ui->cb_day->setMaxCount(32);
                ui->cb_day->addItem("31");
            }
        }
    }
    else if(ui->cb_month->currentIndex() == 2)
    {
        if(leapyear == 0)
        {
           ui->cb_day->setMaxCount(30);
           ui->cb_day->addItem("29");
        }
        else
        {
           ui->cb_day->setMaxCount(29);
        }
    }
    else
    {
        ui->cb_day->setMaxCount(31);
    }
}
/*************************************************************************************/
