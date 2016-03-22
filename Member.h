/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Member.h
 * Author: james
 *
 * Created on March 8, 2016, 6:56 PM
 */

#ifndef MEMBER_H
#define MEMBER_H

#include "date.h"


class Member
{
public:

	Member(QString n, int id, double t, Date exp, bool isEx);

	/*********************************************************************
	 * UpdateExpirationDate(int newMonth,
	 * 						int newDay,
	 * 						int newYear)
	 * -------------------------------------------------------------------
	 * Updates the expiration date with the month, day, and year passed in
	 **********************************************************************/
	void SetExpiration(int newMonth, int newDay, int newYear);

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
	QString GetName() const;

	/*********************************************************************
	 * GetNumber() const
	 * -------------------------------------------------------------------
	 * Returns members id Number that calls this function
	 **********************************************************************/
	int GetID() const;

	/*********************************************************************
	 * ShouldConvertMembership()
	 * -------------------------------------------------------------------
	 * Decides whether the member should switch the membership based on
	 * how much they spend during the year
	 * 	returns a bool true or false
	 **********************************************************************/
	bool ShouldConvertMembership() const;

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
	bool IsExecutive() const;

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

        Date GetExpiration() const;
        
        double GetRebate() const;
        
        bool operator==(const Member& compareTo) const;
        
        void setTotal(double tot){totalSpent = tot;}

private:
	QString name;		// Members Name
	int 	number;		// Membership id member
	Date 	expiration;	// Membership expiration date
	double 	totalSpent;	// Total member spent
    bool    isExecutive;
        
        static const double EXECUTIVE_RENEWAL = 125.00;
        static const double REGULAR_RENEWAL   =  45.00;

};

#endif /* MEMBER */

