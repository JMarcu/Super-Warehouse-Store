#include "date.h"
#include <QDebug>

/**
 * @brief Date::Date
 */
Date::Date()
{
    month = 0;
    day   = 0;
    year  = 0;

}

/**
 * @brief Date::Date
 * @param monthIn
 * @param dayIn
 * @param yearIn
 */
Date::Date(int monthIn,
           int dayIn,
           int yearIn)
{
    month = monthIn;
    day   = dayIn;
    year  = yearIn;
}

/**
 * @brief Date::Date
 * @param dateString
 */
Date::Date(QString dateString){
    year  = dateString.left(4).toInt();
    month = dateString.mid(5, 2).toInt();
    day   = dateString.right(2).toInt();
}

/**
 * @brief Date::~Date
 */
Date::~Date()
{
    month = 0;
    day   = 0;
    year  = 0;
}

/**
 * @brief Date::UpdateDate
 * @param newMonth
 * @param newDay
 * @param newYear
 */
void Date::UpdateDate(int newMonth, int newDay, int newYear)
{
    month = newMonth;
    day   = newDay;
    year  = newYear;
}


/**
 * @brief Date::GetMonth
 * @return
 */
int Date::GetMonth() const
{
    return month;
}

/**
 * @brief Date::GetDay
 * @return
 */
int Date::GetDay() const
{
    return day;
}

/**
 * @brief Date::GetYear
 * @return
 */
int Date::GetYear() const
{
    return year;
}


/**
 * @brief Date::toString
 * @return
 */
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
    date += QString::number(year);
    date += ('/');

    if(month < 10)
    {
        date +=("0");
    }
    date += QString::number(month);

    date += "/";

    if(day < 10)
    {
        date +=("0");
    }

    date += QString::number(day);

    return date;
}
