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

class ExpirationReport {

public:
    ExpirationReport(Date month, list<Member>* members);
    ~ExpirationReport();

    const list<Member>& GetExpiredAccounts() const;
    const Date& GetExpirationMonth() const;

private:
    list<Member> expiredAccounts;
    Date expirationMonth;
};

#endif /* EXPIRATIONREPORT_H_ */


