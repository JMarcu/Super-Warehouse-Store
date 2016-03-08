/*
 * ExpirationReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#ifndef EXPIRATIONREPORT_H_
#define EXPIRATIONREPORT_H_

#include "ExecutiveMember.h"
#include "Database.h"
#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>
#include "sqlite3.h"

class ExpirationReport {

public:
	ExpirationReport();
	virtual ~ExpirationReport();

	ExpirationReport(list<ExecutiveMember> membersIn, Date expirationDate);

	list<ExecutiveMember> GetExpiredAccounts() const;


private:
	list<ExecutiveMember> expiredAccounts;
};

#endif /* EXPIRATIONREPORT_H_ */


