/*
 * RegularMember.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#include "Member.h"

/*********************************************************************
 * RegularMember( string newName,
 *				  int 	 newNumber,
 *				  double newTotal,
 *				  int 	 newMonth,
 *				  int 	 newDay,
 *				  int 	 newYear)
 * -------------------------------------------------------------------
 * Non - default constructor for RegularMember.
 * Sets variables with members passed in
 **********************************************************************/
Member::Member(QString n, int id, double t, Date exp, bool isEx)
{
	name       = n;
	number     = id;
	totalSpent = t;
	expiration = exp;
        isExecutive = isEx;
}

/*********************************************************************
 * UpdateExpirationDate(int newMonth,
 * 						int newDay,
 * 						int newYear)
 * -------------------------------------------------------------------
 * Updates the expiration date with the month, day, and year passed in
 **********************************************************************/
void Member::SetExpiration( int newMonth, int newDay, int newYear)
{
	expiration.UpdateDate(newMonth, newDay, newYear);
}

/*********************************************************************
 * GetRenewalAmount() const
 * -------------------------------------------------------------------
 * Returns the renewal amount for the next year
 **********************************************************************/
float Member::GetRenewalAmount() const
{
	return 45.0;
}

/*********************************************************************
 * GetMember() const
 * -------------------------------------------------------------------
 * Returns the member's name that calls this function
 **********************************************************************/
QString Member::GetName() const
{
    return name;
}

/*********************************************************************
 * GetNumber() const
 * -------------------------------------------------------------------
 * Returns members id Number that calls this function
 **********************************************************************/
int Member::GetID() const
{
	return number;
}

/*********************************************************************
 * ShouldConvertMembership()
 * -------------------------------------------------------------------
 * Decides whether the member should switch the membership based on
 * how much they spend during the year
 * 	returns a bool true or false
 **********************************************************************/
bool Member::ShouldConvertMembership() const
{
	bool convert;

	if( (totalSpent * .035) >= 45.0)
	{
		convert = true;
	}
	else
	{
		convert = false;
	}

	return convert;
}

/*********************************************************************
 * ConvertMembership()
 * -------------------------------------------------------------------
 * Converts the membership to executive or regular
 **********************************************************************/
void Member::ConvertMembership()
{
    isExecutive = !isExecutive;
}



/*********************************************************************
 * GettMembership()
 * -------------------------------------------------------------------
 * returns the type of membership user has
 * 	-returns regular
 **********************************************************************/
bool Member::IsExecutive() const
{
	return isExecutive;
}

/*********************************************************************
 * GetDate()
 * -------------------------------------------------------------------
 * Returns the the date that the membership expires.
 * 	returns Date class
 **********************************************************************/
Date Member::GetDate() const
{
	return expiration;
}

/*********************************************************************
 * GetTotalSpent()
 * -------------------------------------------------------------------
 * Returns the total amount the user spent
 **********************************************************************/
double Member::GetTotalSpent() const
{
	return totalSpent;
}

Date Member::GetExpiration() const{
    return expiration;
}

double Member::GetRebate() const{
    return (isExecutive ? (totalSpent * .035) : 0);
}



