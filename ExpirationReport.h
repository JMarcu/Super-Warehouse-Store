/*
 * ExpirationReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#ifndef EXPIRATIONREPORT_H_
#define EXPIRATIONREPORT_H_

#include "Member.h"
#include <list>

/*A user of your program should be able to enter a month and get a list of all 
 * members whose memberships expire that month as well as the cost to renew 
 * their memberships.
 */
class ExpirationReport {

public:
    ExpirationReport(const Date& month, std::list<Member>* members);
    ~ExpirationReport();

    const std::list<Member>& GetExpiredAccounts() const;
    const Date& GetExpirationMonth() const;

private:
    std::list<Member>* expiredAccounts;
    Date expirationMonth;
};

#endif /* EXPIRATIONREPORT_H_ */


