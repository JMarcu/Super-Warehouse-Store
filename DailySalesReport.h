/*
 * DailySalesReport.h
 *
 *  Created on: Mar 6, 2016
 *      Author: ashlyhernandez
 */

#ifndef DAILYSALESREPORT_H
#define DAILYSALESREPORT_H

#include "Sale.h"
#include "Items.h"
#include "Member.h"
#include <list>

class DailySalesReport {
public:
	DailySalesReport (const list<Sale>&   salesListIn,
                          const list<Member>& mems);
        ~DailySalesReport();

	const list<Sale>& GetDailySales() const;
	const list<Member>& GetAllMembers() const;
	int GetRegularCount() const;
	int GetExecutiveCount() const;

private:
	list<Sale> salesList;
	list<Member> members;
        int regCount;
        int execCount;


};

#endif /* DAILYSALESREPORT_H_ */
