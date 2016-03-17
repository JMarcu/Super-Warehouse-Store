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

class MemberPurchaseReport
{
public:
	MemberPurchaseReport(const Member*     member,
                             const list<Sale>* sales);

	~MemberPurchaseReport();

	const list<Sale>& GetSales()  const;
        const Member&     GetMember() const;
        
private:
    const list<Sale>* sales;
    const Member*     member;
};

#endif /* MEMBERPURCHASEREPORT_H_ */
