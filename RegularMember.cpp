/*
 * RegularMember.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#include "RegularMember.h"



/*********************************************************************
 * RegularMember()
 * -------------------------------------------------------------------
 * Default constructor for RegularMember
 **********************************************************************/
RegularMember::RegularMember()
{
	name.clear();
	number = 0;
	totalSpent = 0;
	expiration.UpdateDate(0,0,0);
}

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
RegularMember::RegularMember( string newName,
							  int 	 newNumber,
							  double newTotal,
							  int 	 newMonth,
							  int 	 newDay,
							  int 	 newYear)
{
	name       = newName;
	number     = newNumber;
	totalSpent = newTotal;
	expiration.UpdateDate(newMonth, newDay, newYear);
}


/*********************************************************************
 * ~RegularMember()
 * -------------------------------------------------------------------
 * Default destructor for RegularMember
 **********************************************************************/
RegularMember::~RegularMember()
{
	name.clear();
	number     = 0;
	totalSpent = 0;
	expiration.UpdateDate(0, 0, 0);
}

/*********************************************************************
 * UpdateExpirationDate(int newMonth,
 * 						int newDay,
 * 						int newYear)
 * -------------------------------------------------------------------
 * Updates the expiration date with the month, day, and year passed in
 **********************************************************************/
void RegularMember::UpdateExpirationDate( int newMonth,
										  int newDay,
										  int newYear)
{
	expiration.UpdateDate(newMonth, newDay, newYear);
}

/*********************************************************************
 * SetMember(string newName,
 * 			 int    newNumber,
 * 			 Date   newDate,
 * 			 double newTotal)
 * -------------------------------------------------------------------
 * Changes the variables for the regular member with the variables
 * passed in
 **********************************************************************/
void RegularMember::SetMember( string newName,
								 int    newNumber,
								 int    newMonth,
								 int    newDay,
								 int    newYear,
								 double newTotal)
{
	name       = newName;
	number     = newNumber;
	expiration.UpdateDate(newMonth, newDay, newYear);
	totalSpent = newTotal;
}

/*********************************************************************
 * GetRenewalAmount() const
 * -------------------------------------------------------------------
 * Returns the renewal amount for the next year
 **********************************************************************/
float RegularMember::GetRenewalAmount() const
{
	return 45.0;
}

/*********************************************************************
 * GetMember() const
 * -------------------------------------------------------------------
 * Returns the member's name that calls this function
 **********************************************************************/
string RegularMember::GetMember() const
{
	return name;
}

/*********************************************************************
 * GetNumber() const
 * -------------------------------------------------------------------
 * Returns members id Number that calls this function
 **********************************************************************/
int RegularMember::GetNumber() const
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
bool RegularMember::ShouldConvertMembership()
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
void RegularMember::ConvertMembership()
{
	//db.ConvertMember(this);
}



/*********************************************************************
 * GettMembership()
 * -------------------------------------------------------------------
 * returns the type of membership user has
 * 	-returns regular
 **********************************************************************/
string RegularMember::GetMembership()
{
	return "regular";
}

/*********************************************************************
 * GetDate()
 * -------------------------------------------------------------------
 * Returns the the date that the membership expires.
 * 	returns Date class
 **********************************************************************/
Date RegularMember::GetDate() const
{
	return expiration;
}

/*********************************************************************
 * GetTotalSpent()
 * -------------------------------------------------------------------
 * Returns the total amount the user spent
 **********************************************************************/
double RegularMember::GetTotalSpent() const
{
	return totalSpent;
}




