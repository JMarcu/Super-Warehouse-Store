/*
 * RegularMember.h
 */

#ifndef REGULARMEMBER_H_
#define REGULARMEMBER_H_

#include "Date.h"


class RegularMember
{
public:

	/*********************************************************************
	 * RegularMember()
	 * -------------------------------------------------------------------
	 * Constructor for class RegularMember
	 **********************************************************************/
	RegularMember();

	/*********************************************************************
	 * RegularMember(string newName,
	 * 				 int    newNumber,
	 * 			     Date   newDate,
	 * 			     double newTotal)
	 * -------------------------------------------------------------------
	 * Constructor for class ExecutiveMember that sets the variables with
	 * the arguments passed in
	 **********************************************************************/
	RegularMember(string newName,
				  int 	 newNumber,
				  double newTotal,
				  int 	 newMonth,
				  int 	 newDay,
				  int 	 newYear);


	/*********************************************************************
	 * ~RegularMember()
	 * -------------------------------------------------------------------
	 * Destructor for class RegularMember
	 **********************************************************************/
	virtual ~RegularMember();

	/*********************************************************************
	 * UpdateExpirationDate(int newMonth,
	 * 						int newDay,
	 * 						int newYear)
	 * -------------------------------------------------------------------
	 * Updates the expiration date with the month, day, and year passed in
	 **********************************************************************/
	void UpdateExpirationDate(int newMonth,
								int newDay,
								int newYear);

	/*********************************************************************
	 * SetMember(string newName,
	 * 			 int    newNumber,
	 * 			 Date   newDate,
	 * 			 double newTotal)
	 * -------------------------------------------------------------------
	 * Changes the variables for the regular member with the variables
	 * passed in
	 **********************************************************************/
	void SetMember(string newName,
				   	 int    newNumber,
				   	 int    newMonth,
					 int    newDay,
					 int    newYear,
				     double newTotal);

	/*********************************************************************
	 * GetRenewalAmount() const
	 * -------------------------------------------------------------------
	 * Returns the renewal amount for the next year
	 **********************************************************************/
	float GetRenewalAmount() const;

	/*********************************************************************
	 * GetMember() const
	 * -------------------------------------------------------------------
	 * Returns the member's name that calls this function
	 **********************************************************************/
	string GetMember() const;

	/*********************************************************************
	 * GetNumber() const
	 * -------------------------------------------------------------------
	 * Returns members id Number that calls this function
	 **********************************************************************/
	int GetNumber() const;

	/*********************************************************************
	 * ShouldConvertMembership()
	 * -------------------------------------------------------------------
	 * Decides whether the member should switch the membership based on
	 * how much they spend during the year
	 * 	returns a bool true or false
	 **********************************************************************/
	bool ShouldConvertMembership();

	/*********************************************************************
	 * ConvertMembership()
	 * -------------------------------------------------------------------
	 * Converts the membership to executive or regular
	 **********************************************************************/
	void ConvertMembership();

	/*********************************************************************
	 * GettMembership()
	 * -------------------------------------------------------------------
	 * returns the type of membership user has
	 * 	-returns regular
	 **********************************************************************/
	string GetMembership();

	/*********************************************************************
	 * GetDate()
	 * -------------------------------------------------------------------
	 * Returns the the date that the membership expires.
	 * 	returns Date class
	 **********************************************************************/
	Date GetDate() const;


	/*********************************************************************
	 * GetTotalSpent()
	 * -------------------------------------------------------------------
	 * Returns the total amount the user spent
	 **********************************************************************/
	double GetTotalSpent() const;





private:
	string 	name;		// Members Name
	int 	number;		// Membership id member
	Date 	expiration;	// Membership expiration date
	double 	totalSpent;	// Total member spent

};

#endif /* REGULARMEMBER_H_ */
