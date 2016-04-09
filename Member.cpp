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
/**
 * @brief Member::Member
 * @param n
 * @param id
 * @param t
 * @param exp
 * @param isEx
 */
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
/**
 * @brief Member::SetExpiration
 * @param newMonth
 * @param newDay
 * @param newYear
 */
void Member::SetExpiration( int newMonth, int newDay, int newYear)
{
	expiration.UpdateDate(newMonth, newDay, newYear);
}

/*********************************************************************
 * GetRenewalAmount() const
 * -------------------------------------------------------------------
 * Returns the renewal amount for the next year
 **********************************************************************/
/**
 * @brief Member::GetRenewalAmount
 * @return
 */
float Member::GetRenewalAmount() const
{
    return (isExecutive ? EXECUTIVE_RENEWAL : REGULAR_RENEWAL);
}

/*********************************************************************
 * GetMember() const
 * -------------------------------------------------------------------
 * Returns the member's name that calls this function
 **********************************************************************/
/**
 * @brief Member::GetName
 * @return
 */
QString Member::GetName() const
{
    return name;
}

/*********************************************************************
 * GetNumber() const
 * -------------------------------------------------------------------
 * Returns members id Number that calls this function
 **********************************************************************/
/**
 * @brief Member::GetID
 * @return
 */
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
/**
 * @brief Member::ShouldConvertMembership
 * @return
 */
bool Member::ShouldConvertMembership() const
{
    bool convert;

    if(isExecutive){
        convert = (EXECUTIVE_RENEWAL - GetRebate()) > REGULAR_RENEWAL;
    }
    else{
        convert = REGULAR_RENEWAL > (EXECUTIVE_RENEWAL - totalSpent * 0.035);
    }
    
    return convert;
}

/*********************************************************************
 * ConvertMembership()
 * -------------------------------------------------------------------
 * Converts the membership to executive or regular
 **********************************************************************/
/**
 * @brief Member::ConvertMembership
 */
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
/**
 * @brief Member::IsExecutive
 * @return
 */
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
/**
 * @brief Member::GetDate
 * @return
 */
Date Member::GetDate() const
{
	return expiration;
}

/*********************************************************************
 * GetTotalSpent()
 * -------------------------------------------------------------------
 * Returns the total amount the user spent
 **********************************************************************/
/**
 * @brief Member::GetTotalSpent
 * @return
 */
double Member::GetTotalSpent() const
{
	return totalSpent;
}

/**
 * @brief Member::GetExpiration
 * gets the expiration yup
 * @return expiration Date
 */
Date Member::GetExpiration() const{
    return expiration;
}

/**
 * @brief Member::GetRebate
 * @return
 */
double Member::GetRebate() const{
    return (isExecutive ? (totalSpent * .035) : 0);
}

/**
 * @brief Member::operator ==
 * @param compareTo
 * @return
 */
bool Member::operator==(const Member& compareTo) const{
    return number == compareTo.GetID();
}
