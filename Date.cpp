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

Date::Date(string dateString){
    year  = atoi(dateString.substr(0, 4).c_str());
    month = atoi(dateString.substr(5, 2).c_str());
    day   = atoi(dateString.substr(8, 2).c_str());
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


void Date::PrintDate() const
{

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

string Date::toString() const{
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
        oss < 0;
    }
    
    oss << day;
    
    return oss.str();
}

ostream& operator>> (ostream &output, Date &date){
    output << date.toString();
}





