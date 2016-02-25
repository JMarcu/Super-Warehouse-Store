/*
 * Database.h
 *
 *  Created on: Feb 24, 2016
 *      Author: jmarcu0
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <list>
#include "Reports.h"
#include "Date.h"
using namespace std;

class Database{
private:

public:
	//Reports
	DailySalesReport getDailySalesReport(Date day) const;
	TotalPurchaseReport getTotalPurchaseReport() const;
	TotalItemReport getTotalItemReport() const;
	RebateReport getRebateReport() const;
	ExpirationReport getExpirationReport(Date month) const;
	ItemReport getItemReport(const Item& item) const;
	MemberPurchaseReport getMemberPurchaseReport(int memberID) const;
	MemberPurchaseReport getMemberPurchaseReport(string memberName) const;
	RegularConversionReport getRegularConversionReport() const;
	ExecutiveConversionReport getExecutiveConversionReport() const;

	//Modifiers
	void AddMember(const Member& member);
	void DeleteMember(const Member& member);
	void AddItem(const Item& item);
	void DeleteItem(const Item& item);
	void AddSale(const Sale& sale);
	void DeleteSale(const Sale& sale);
};



#endif /* DATABASE_H_ */
