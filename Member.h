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

    /**
     * @brief Member
     * @param n
     * @param id
     * @param t
     * @param exp
     * @param isEx
     */
	Member(QString n, int id, double t, Date exp, bool isEx);

    /**
     * @brief SetExpiration
     * @param newMonth
     * @param newDay
     * @param newYear
     */
	void SetExpiration(int newMonth, int newDay, int newYear);

    /**
     * @brief GetRenewalAmount
     * @return
     */
	float GetRenewalAmount() const;

    /**
     * @brief GetName
     * @return
     */
	QString GetName() const;

    /**
     * @brief GetID
     * @return
     */
	int GetID() const;

    /**
     * @brief ShouldConvertMembership
     * @return
     */
	bool ShouldConvertMembership() const;

    /**
     * @brief ConvertMembership
     */
	void ConvertMembership();

    /**
     * @brief IsExecutive
     * @return
     */
	bool IsExecutive() const;

    /**
     * @brief GetDate
     * @return
     */
	Date GetDate() const;

    /**
     * @brief GetTotalSpent
     * @return
     */
	double GetTotalSpent() const;

    /**
     * @brief GetExpiration
     * @return
     */
    Date GetExpiration() const;

    /**
     * @brief GetRebate
     * @return
     */
    double GetRebate() const;

    /**
     * @brief operator ==
     * @param compareTo
     * @return
     */
    bool operator==(const Member& compareTo) const;

    /**
     * @brief setTotal
     * @param tot
     */
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

