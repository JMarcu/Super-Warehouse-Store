/*
 * ExpirationReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "ExpirationReport.h"

ExpirationReport::ExpirationReport(const Date& month, std::list<Member>* members){
    expirationMonth = month;
    expiredAccounts = members;
}

ExpirationReport::~ExpirationReport(){
    expiredAccounts->clear();
    delete expiredAccounts;
}

const std::list<Member>& ExpirationReport::GetExpiredAccounts() const{
    return *expiredAccounts;
}

const Date& ExpirationReport::GetExpirationMonth() const{
    return expirationMonth;
}
