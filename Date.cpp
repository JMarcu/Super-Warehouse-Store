/*
 * Date.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#include "Date.h"
#include <stdlib.h>
using namespace std;

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
    ostringstream oss;
    
    if(year < 1000){
        oss << 0;
        if(year < 100){
            oss << 0;
            if(year < 10){
                oss << 0;
            }
        }
    }
    
    oss << year << "/";
    
    if(month < 10){
        oss << 0;
    }
    
    oss << month << "/";

    if(day < 10){
        oss << 0;
    }
    
    oss << day;
    
    return QString(oss.str().c_str());
}