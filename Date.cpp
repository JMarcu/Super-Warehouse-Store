/*
 * Date.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#include "Date.h"

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






