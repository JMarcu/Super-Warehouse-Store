#include "adddate.h"
#include "ui_adddate.h"

AddDate::AddDate(int index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDate)
{
    ui->setupUi(this);

    this->index =index;

    if(index == 1)
    {
        ui->header->setText("Enter a Month");
        ui->day->hide();
    }
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

    if(index == 0)
    {

        date.UpdateDate(ui->month->currentIndex(),
                        ui->day->currentIndex(), year);
    }
    else
    {
        date.UpdateDate(ui->month->currentIndex(),
                        0, year);
    }

   emit DateSelected(date);

    hide();

}

Date AddDate::ReturnDate() const
{
    return date;
}
