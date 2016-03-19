/*
 * MemberPurchaseReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#ifndef MEMBERPURCHASEREPORT_H_
#define MEMBERPURCHASEREPORT_H_

#include "Sale.h"
#include "Member.h"
#include <list>

/* A user of your program should be able to enter a membership number or name 
 * and get a list of the total purchases per that member.
 */
class MemberPurchaseReport
{
public:
	MemberPurchaseReport(Member*     member,
                             list<Sale>* sales);

	~MemberPurchaseReport();

	const list<Sale>& GetSales()  const;
        const Member&     GetMember() const;
        
private:
    list<Sale>* sales;
    Member*     member;
};

#endif /* MEMBERPURCHASEREPORT_H_ */
