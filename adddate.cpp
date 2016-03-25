#include "adddate.h"
#include "ui_adddate.h"

AddDate::AddDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDate)
{
    ui->setupUi(this);
}

AddDate::~AddDate()
{
    delete ui;
}

void AddDate::on_buttonBox_rejected()
{
    hide();
}

void AddDate::on_buttonBox_accepted()
{
    int year;

    switch(ui->year->currentIndex())
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

    date.UpdateDate(ui->month->currentIndex(),
                    ui->day->currentIndex(), year);




   emit DateSelected(date);

    hide();

}

Date AddDate::ReturnDate() const
{
    return date;
}

/*******************************DATE COMBOBOX ALGORITHM HERE***************************/
void AddDate::on_month_currentIndexChanged(int index)
{
    int leap = ui->year->currentText().toInt(0,10) % 4;

    if(ui->month->currentIndex() == 1 || ui->month->currentIndex() == 3 ||
       ui->month->currentIndex() == 5 || ui->month->currentIndex() == 7 ||
       ui->month->currentIndex() == 8 || ui->month->currentIndex() == 10
       || ui->month->currentIndex() == 12)
    {
        if(ui->day->maxCount() < 32)
        {
            if(ui->day->maxCount() < 31)
            {
                if(ui->day->maxCount() < 30)
                {
                    ui->day->setMaxCount(32);
                    ui->day->addItem("29");
                    ui->day->addItem("30");
                    ui->day->addItem("31");
                }
                else
                {
                    ui->day->setMaxCount(32);
                    ui->day->addItem("30");
                    ui->day->addItem("31");
                }
            }
            else
            {
                ui->day->setMaxCount(32);
                ui->day->addItem("31");
            }
        }
    }
    else if(ui->month->currentIndex() == 2)
    {
        if(leap == 0 || ui->year->currentIndex() == 1)
        {
           ui->day->setMaxCount(30);

        }
        else
        {
           ui->day->setMaxCount(29);
        }
    }
    else
    {
        ui->day->setMaxCount(31);
    }
}

void AddDate::on_year_currentIndexChanged(int index)
{
    int leapyear = ui->year->currentText().toInt(0,10) % 4;

    if(ui->day->maxCount() < 32)
    {
        if(ui->day->maxCount() < 31)
        {
            if(ui->day->maxCount() < 30)
            {
                ui->day->setMaxCount(32);
                ui->day->addItem("29");
                ui->day->addItem("30");
                ui->day->addItem("31");
            }
            else
            {
                ui->day->setMaxCount(32);
                ui->day->addItem("30");
                ui->day->addItem("31");
            }
        }
        else
        {
            ui->day->setMaxCount(32);
            ui->day->addItem("31");
        }
    }

    if(ui->month->currentIndex() == 2)
    {
        if(ui->year->currentIndex() == 1 && leapyear == 0)
        {
            ui->day->setMaxCount(30);
        }
        else
        {
            ui->day->setMaxCount(29);
        }
    }
}
/************************************************************************************/
