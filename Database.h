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
#include "Member.h"
#include "Date.h"
#include "Items.h"
#include "Sale.h"
#include <sstream>
#include <list>
#include "sqlite3.h"

#include "DailySalesReport.h"
#include "ItemReport.h"
#include "MemberPurchaseReport.h"
#include "TotalItemReport.h"
#include "RebatesReport.h"
#include "TotalPurchaseReport.h"
#include "ExpirationReport.h"
#include "RegularConversionReport.h"
#include "ExecutiveConversionReport.h"

using namespace std;

class Database{
private:
    sqlite3* db;
   
public:
    Database(string dbname);
    ~Database();

    //Accessors
    Member* GetMember(int id) const;
    Member* GetMember(QString name) const;
    list<Member>* GetAllMembers() const;
    list<Member>* GetRegularMembers() const;
    list<Member>* GetExecutiveMembers() const;
    list<Sale>* GetSales(Date day) const;
    list<Sale>* GetSales(const Item& item) const;
    list<Sale>* GetSales(const Member& member) const;
    list<Sale>* GetAllSales() const;
    list<Item>* GetAllItems() const;

    //Modifiers
    void AddMember(const RegularMember& member);
    void AddMember(const ExecutiveMember& member);
    void DeleteMember(const RegularMember& member);
    void DeleteMember(const ExecutiveMember& member);
    void AddItem(const Item& item);
    void DeleteItem(const Item& item);
    void AddSale(const Sale& sale);
    void DeleteSale(const Sale& sale);
    
    //Report Builders
    const DailySalesReport* GetDailySalesReport(Date day) const;
    const TotalPurchaseReport* GetTotalPurchaseReport() const;
    const TotalItemReport* GetTotalItemReport() const;
    const RebatesReport* GetRebatesReport() const;
    const ExpirationReport* GetExpirationReport(Date month) const;
    const ItemReport* GetItemReport(const Item& item) const;
    const MemberPurchaseReport* GetMemberPurchaseReport(int id) const;
    const MemberPurchaseReport* GetMemberPurchaseReport(QString name) const;
    const RegularConversionReport* GetRegularConversionReport() const;
    const ExecutiveConversionReport* GetExecutiveConversionReport() const;
};

//Callback Functions
int getMemberCallback(void* mem, int colCount, char** results, char** colNames);



#endif /* DATABASE_H_ */
