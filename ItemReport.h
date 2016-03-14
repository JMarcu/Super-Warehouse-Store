/*
 * ItemReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#ifndef ITEMREPORT_H_
#define ITEMREPORT_H_

#include "ExecutiveMember.h"
#include "Database.h"
#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>
#include "sqlite3.h"




class ItemReport
{
public:
	ItemReport();

	ItemReport(list<Sale> item,
	           QString itemName);

	virtual ~ItemReport();

	list<Sale> GetTotalSales() const;




private:
	list<Sale> totalSales;


};

#endif /* ITEMREPORT_H_ */
