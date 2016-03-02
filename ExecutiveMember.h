/*
 * ExecutiveMember.h
 */

#ifndef EXECUTIVEMEMBER_H_
#define EXECUTIVEMEMBER_H_

#include "RegularMember.h"

class ExecutiveMember : public RegularMember
{
public:
	/*********************************************************************
	 * ExecutiveMember()
	 * -------------------------------------------------------------------
	 * Constructor for class ExecutiveMember
	 **********************************************************************/
	ExecutiveMember();

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
	ExecutiveMember(string newName,
			  	    int    newNumber,
			  	    int    newMonth,
				    int    newDay,
				    int    newYear,
			  	    double newTotal,
			  	    int    newRebate);

	/*********************************************************************
	 * ~ExecutiveMember()
	 * -------------------------------------------------------------------
	 * Destructor for class ExecutiveMember
	 **********************************************************************/
	virtual ~ExecutiveMember();

	/*********************************************************************
	 * GetRebate()
	 * -------------------------------------------------------------------
	 * Returns the total rebate amount for the member
	 **********************************************************************/
	int GetRebate() const;

	/*********************************************************************
	 * SetRebate()
	 * -------------------------------------------------------------------
	 * Sets the rebate amount for the executive member based on the
	 * total amount spent during the year
	 **********************************************************************/
	void SetRebate();

	/*********************************************************************
	 * GetMembership()
	 * -------------------------------------------------------------------
	 * Returns the type of membership the user has
	 * 	returns "executive"
	 **********************************************************************/
	string GetMembership();

	/*********************************************************************
	 * GetRenewalAmount()
	 * -------------------------------------------------------------------
	 * Returns how much it would cost the member to renew their membership
	 **********************************************************************/
	float GetRenewalAmount();

	/*********************************************************************
	 * ShouldConvertMembership()
	 * -------------------------------------------------------------------
	 * Decides whether the user should convert their membership based on
	 * how much they spent and how much their renewal amount is
	 **********************************************************************/
	bool ShouldConvertMembership();



	int rebate;	// Rebate amount for executive member
};

#endif /* EXECUTIVEMEMBER_H_ */
