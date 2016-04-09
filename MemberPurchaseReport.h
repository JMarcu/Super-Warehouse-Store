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
    /**
     * @brief MemberPurchaseReport
     * @param member
     * @param sales
     */
	MemberPurchaseReport(Member*     member,
                             std::list<Sale>* sales);

	~MemberPurchaseReport();

    /**
     * @brief GetSales
     * @return
     */
    const std::list<Sale>& GetSales()  const;
        const Member&     GetMember() const;
        
private:
    std::list<Sale>* sales;
    Member*     member;
};

#endif /* MEMBERPURCHASEREPORT_H_ */
