/*
 * MemberPurchaseReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#ifndef MEMBERPURCHASEREPORT_H_
#define MEMBERPURCHASEREPORT_H_


#include "ExecutiveMember.h"
#include "Database.h"
#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>
#include "sqlite3.h"

class MemberPurchaseReport
{
public:
	MemberPurchaseReport();

	MemberPurchaseReport(list<RegularMember>   regularIn,
					     list<ExecutiveMember> executiveIn,
					     list<Sale> 		   salesIn,
					     string    			   memberName);

	MemberPurchaseReport(list<Sale> 		     salesIn,
						 int				     idIn);

	virtual ~MemberPurchaseReport();

	MemberPurchaseReport GetSales() const;

	list<Sale> 			memberSales;

};

#endif /* MEMBERPURCHASEREPORT_H_ */
