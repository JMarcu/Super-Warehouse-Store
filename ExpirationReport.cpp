/*
 * ExpirationReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "ExpirationReport.h"

ExpirationReport::ExpirationReport(const Date& month, list<Member>* members){
    expirationMonth = month;
    expiredAccounts = members;
}

ExpirationReport::~ExpirationReport(){
    expiredAccounts->clear();
    delete expiredAccounts;
}

const list<Member>& ExpirationReport::GetExpiredAccounts() const{
    return *expiredAccounts;
}

const Date& ExpirationReport::GetExpirationMonth() const{
    return expirationMonth;
}