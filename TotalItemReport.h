/*
 * TotalItemReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#ifndef TOTALITEMREPORT_H_
#define TOTALITEMREPORT_H_


#include "ExecutiveMember.h"
#include "Database.h"
#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>
#include "sqlite3.h"

class TotalItemReport
{
public:
	TotalItemReport();

	TotalItemReport(list<Sale> soldIn);

	virtual ~TotalItemReport();



private:
	list<Sale> sales;

};

#endif /* TOTALITEMREPORT_H_ */
