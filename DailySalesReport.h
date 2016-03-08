/*
 * DailySalesReport.h
 *
 *  Created on: Mar 6, 2016
 *      Author: ashlyhernandez
 */

#ifndef DAILYSALESREPORT_H
#define DAILYSALESREPORT_H

#include "ExecutiveMember.h"
#include "Database.h"
#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>
#include "sqlite3.h"



class DailySalesReport {
public:
	DailySalesReport();
	virtual ~DailySalesReport();

	DailySalesReport ( list<Sale> 		     salesListIn,
					   list<RegularMember>   regularMembersIn,
					   list<ExecutiveMember> execMembersIn);

	list<Sale> GetDailySales() const;

	list<RegularMember> GetAllMembers() const;

	int GetRegularCount(list<RegularMember>   regularMembers) const;

	int GetExecutiveCount(list<ExecutiveMember> execMembers) const;





private:
	list<Sale>   		  salesList;
	list<RegularMember>   allMembers;


};

#endif /* DAILYSALESREPORT_H_ */
