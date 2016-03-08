/*
 * RebatesReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#ifndef REBATESREPORT_H_
#define REBATESREPORT_H_


#include "ExecutiveMember.h"
#include "Database.h"
#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>
#include "sqlite3.h"

class RebatesReport
{
public:
	RebatesReport();

	RebatesReport(list<ExecutiveMember> membersIn);

	virtual ~RebatesReport();

	list<ExecutiveMember> GetRebatesReport() const;


private:
	list<ExecutiveMember> rebates;
};

#endif /* REBATESREPORT_H_ */
