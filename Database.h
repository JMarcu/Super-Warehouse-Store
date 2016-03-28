/*
 * Database.h
 *
 *  Created on: Feb 24, 2016
 *      Author: jmarcu0
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "Member.h"
#include "date.h"
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
    std::list<Member>* GetAllMembers() const;
    std::list<Member>* GetRegularMembers() const;
    std::list<Member>* GetExecutiveMembers() const;
    std::list<Sale>* GetSales(Date day) const;
   std::list<Sale>* GetSales(const Item& item) const;
    std::list<Sale>* GetSales(const Member& member) const;
    std::list<Sale>* GetAllSales() const;
    std::list<Item>* GetAllItems() const;

    //Modifiers
    void AddMember(const Member& member);
    void DeleteMember(const Member& member);
    void UpdateMember(const Member& member);
    void AddItem(const Item& item);
    void UpdateItem(const Item& item);
    void DeleteItem(const Item& item);
    void AddSale(const Sale& sale);
    void DeleteSale(const Sale& sale);
    
    /**************************************************************************
     * REPORT BUILDERS - These will generate pointers to reports. For 
     * information on what the reports contain, see their documentation.
     **************************************************************************/
    const DailySalesReport* GetDailySalesReport(Date day, int memType=0) const;
    const TotalPurchaseReport* GetTotalPurchaseReport() const;
    const TotalItemReport* GetTotalItemReport() const;
    const RebatesReport* GetRebatesReport() const;
    const ExpirationReport* GetExpirationReport(const Date& month) const;
    const ItemReport* GetItemReport(const Item& item) const;
    const MemberPurchaseReport* GetMemberPurchaseReport(int id) const;
    const MemberPurchaseReport* GetMemberPurchaseReport(QString name) const;
    const RegularConversionReport* GetRegularConversionReport() const;
    const ExecutiveConversionReport* GetExecutiveConversionReport() const;
};

//Callback Functions
int getMemberCallback(void* mem, int colCount, char** results, char** colNames);



#endif /* DATABASE_H_ */
