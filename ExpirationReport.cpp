/*
 * ExpirationReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "ExpirationReport.h"

/**
 * @brief ExpirationReport::ExpirationReport
 * @param month
 * @param members
 */
ExpirationReport::ExpirationReport(const Date& month, std::list<Member>* members){
    expirationMonth = month;
    expiredAccounts = members;
}

/**
 * @brief ExpirationReport::~ExpirationReport
 */
ExpirationReport::~ExpirationReport(){
    expiredAccounts->clear();
    delete expiredAccounts;
}

/**
 * @brief ExpirationReport::GetExpiredAccounts
 * @return
 */
const std::list<Member>& ExpirationReport::GetExpiredAccounts() const{
    return *expiredAccounts;
}

/**
 * @brief ExpirationReport::GetExpirationMonth
 * @return
 */
const Date& ExpirationReport::GetExpirationMonth() const{
    return expirationMonth;
}
