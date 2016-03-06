/*
 * Database.h
 *
 *  Created on: Feb 24, 2016
 *      Author: jmarcu0
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "RegularMember.h"
#include "ExecutiveMember.h"
#include "Date.h"
#include "Items.h"
#include "Sale.h"
#include <sstream>
#include <list>
#include "sqlite3.h"

using namespace std;

class Database{
private:
    sqlite3* db;
   
public:
    Database(string dbname);
    ~Database();
    
	//Reports
//	DailySalesReport getDailySalesReport(Date day) const;
//	TotalPurchaseReport getTotalPurchaseReport() const;
//	TotalItemReport getTotalItemReport() const;
//	RebateReport getRebateReport() const;
//	ExpirationReport getExpirationReport(Date month) const;
//	ItemReport getItemReport(const Item& item) const;
//	MemberPurchaseReport getMemberPurchaseReport(int memberID) const;
//	MemberPurchaseReport getMemberPurchaseReport(string memberName) const;
//	RegularConversionReport getRegularConversionReport() const;
//	ExecutiveConversionReport getExecutiveConversionReport() const;

	//Modifiers
	void AddMember(const RegularMember& member);
        void AddMember(const ExecutiveMember& member);
	void DeleteMember(const RegularMember& member);
        void DeleteMember(const ExecutiveMember& member);
	void AddItem(const Item& item);
	void DeleteItem(const Item& item);
	void AddSale(const Sale& sale);
	void DeleteSale(const Sale& sale);
};



#endif /* DATABASE_H_ */
