/*
 * ExecutiveMember.cpp
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#include "ExecutiveMember.h"


/*********************************************************************
 * ExecutiveMember()
 * -------------------------------------------------------------------
 * Default Construct for ExecutiveMember
 **********************************************************************/
ExecutiveMember::ExecutiveMember() :RegularMember()
{
	rebate = 0;
}

/*********************************************************************
 * ExecutiveMember(string newName,
		  	    int    newNumber,
		  	    Date   newDate,
		  	    double newTotal,
		  	    int newRebate);
 * -------------------------------------------------------------------
 * Constructor for class ExecutiveMember that sets the variables
 * with the arguments passed in
 **********************************************************************/
ExecutiveMember::ExecutiveMember(string newName,
							   	 int    newNumber,
								 int    newMonth,
								 int    newDay,
							 	 int    newYear,
								 double newTotal,
								 int    newRebate)
								 : RegularMember(newName,newNumber, newTotal,
										 newMonth, newDay, newYear)
{
	rebate = newRebate;
}

/*********************************************************************
 * ~ExecutiveMember()
 * -------------------------------------------------------------------
 * Default Destructor for ExecutiveMember
 **********************************************************************/

ExecutiveMember::~ExecutiveMember()
{
	rebate = 0;
}

/*********************************************************************
 * GetRebate()
 * -------------------------------------------------------------------
 * Returns the total rebate amount for the member
 **********************************************************************/
int ExecutiveMember::GetRebate() const
{
	return rebate;
}

/*********************************************************************
 * SetRebate()
 * -------------------------------------------------------------------
 * Sets the rebate amount for the executive member based on the
 * total amount spent during the year
 **********************************************************************/
void ExecutiveMember::SetRebate()
{
	rebate = rebate + (GetTotalSpent() * .035);
}

/*********************************************************************
 * GetMembership()
 * -------------------------------------------------------------------
 * Returns the type of membership the user has
 * 	returns "executive"
 **********************************************************************/
string ExecutiveMember::GetMembership()
{
	return "executive";
}

/*********************************************************************
 * GetRenewalAmount()
 * -------------------------------------------------------------------
 * Returns how much it would cost the member to renew their membership
 **********************************************************************/
float ExecutiveMember::GetRenewalAmount()
{
	return 125.00;
}

/*********************************************************************
 * ShouldConvertMembership()
 * -------------------------------------------------------------------
 * Decides whether the user should convert their membership based on
 * how much they spent and how much their renewal amount is
 **********************************************************************/
bool ExecutiveMember::ShouldConvertMembership()
{
	bool convert;

	if(rebate < GetRenewalAmount())
	{
		convert = true;
	}
	else
	{
		convert = false;
	}

	return convert;
}



