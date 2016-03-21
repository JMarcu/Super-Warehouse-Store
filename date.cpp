#include "date.h"
#include <QDebug>

Date::Date()
{
    month = 0;
    day   = 0;
    year  = 0;

}

Date::Date(int monthIn,
           int dayIn,
           int yearIn)
{
    month = monthIn;
    day   = dayIn;
    year  = yearIn;
}

Date::Date(QString dateString){
    year  = dateString.left(4).toInt();
    month = dateString.mid(5, 2).toInt();
    day   = dateString.right(2).toInt();
}

Date::~Date()
{
    month = 0;
    day   = 0;
    year  = 0;
}


void Date::UpdateDate(int newMonth, int newDay, int newYear)
{
    month = newMonth;
    day   = newDay;
    year  = newYear;
}

int Date::GetMonth() const
{
    return month;
}


int Date::GetDay() const
{
    return day;
}


int Date::GetYear() const
{
    return year;
}

QString Date::toString() const{
    QString date;


    date += "";

    if(year < 1000)
    {
        date +=("0");

        if(year < 100)
        {
            date +=("0");
            if(year < 10)
            {
                date +=("0");
            }
        }
    }

    if(month < 10)
    {
        date +=("0");
    }
    date += QString::number(month);

    date += "-";

    if(day < 10)
    {
        date +=("0");
    }

    date += QString::number(day);

    date += "-";

    date += QString::number(year);

    return date;
}
