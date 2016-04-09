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

    /**
     * @brief GetMember
     * @param id - id of Member to return
     * @return - Member of id passed in
     */
    Member* GetMember(int id) const;

    /**
     * @brief GetMember
     * @param name - name of Member to return
     * @return - Member whose name was passed in
     */
    Member* GetMember(QString name) const;

    /**
     * @brief GetAllMembers
     * @return - a list of all Members in database
     */
    std::list<Member>* GetAllMembers() const;

    /**
     * @brief GetRegularMembers
     * @return - list of regular Member
     */
    std::list<Member>* GetRegularMembers() const;

    /**
     * @brief GetExecutiveMembers
     * @return - list of Executive Member
     */
    std::list<Member>* GetExecutiveMembers() const;

    /**
     * @brief GetSales
     * @param day - Date of Sale 's made that day
     * @return  - list of Sale 's made on Date passed in
     */
    std::list<Sale>* GetSales(Date day) const;

    /**
    * @brief GetSales
    * @param item - Item to find how many purchases were made
    * @return - List of Sale 's made with Item passed in
    */

    std::list<Sale>* GetSales(const Item& item) const;

    /**
     * @brief GetSales
     * @param member - Member to find what purchases they made
     * @return - list of Sale 's Member made
     */
    std::list<Sale>* GetSales(const Member& member) const;

    /**
     * @brief GetAllSales
     * @return - List of all Sales 's made
     */
    std::list<Sale>* GetAllSales() const;

    /**
     * @brief GetAllItems
     * @return  - list of all Item 's in inventory
     */
    std::list<Item>* GetAllItems() const;

    /**
     * @brief AddMember
     * @param member - Member to be added to database
     *  - Adds member to datatbase
     */
    void AddMember(const Member& member);

    /**
     * @brief DeleteMember
     * @param member - Member to dekete from database
     */
    void DeleteMember(const Member& member);

    /**
     * @brief UpdateMember
     * @param member - Member to Update
     *  - updates Member passed in
     */
    void UpdateMember(const Member& member);

    /**
     * @brief AddItem
     * @param item - Item to be added to database
     * - adds Item to database
     */
    void AddItem(const Item& item);

    /**
     * @brief UpdateItem
     * @param item - Item to be updated to database
     * - updates Item passed in
     */
    void UpdateItem(const Item& item);

    /**
     * @brief DeleteItem
     * @param item - Item to be delted from database
     *  - deletes Item passed in
     */
    void DeleteItem(const Item& item);
    /**
     * @brief AddSale
     * @param sale - Sale to be added
     *  - adds Sale to database
     */
    void AddSale(const Sale& sale);

    /**
     * @brief DeleteSale
     * @param sale - Sale to be deleted from database
     *  - deltes Sale passed in from database
     */
    void DeleteSale(const Sale& sale);
    

    /**
     * @brief GetDailySalesReport -
     *      Gets list of Sale 's and Member 's who bought on Date passed in
     * @param day - Date to get Sale 's from
     * @param memType - Membership Type to view Sale 's from
     * @return - DailySalesReport
     */
    const DailySalesReport* GetDailySalesReport(Date day, int memType=0) const;

    /**
     * @brief GetTotalPurchaseReport
     *  - Gets list of all purchases made by Members
     * @return TotalPurchaseReport
     */
    const TotalPurchaseReport* GetTotalPurchaseReport() const;

    /**
     * @brief GetTotalItemReport
     *  - Gets a list of all Items in Inventory
     * @return TotalItemReport
     */
    const TotalItemReport* GetTotalItemReport() const;

    /**
     * @brief GetRebatesReport
     *  - Gets a list of Executive Member 's rebates due
     * @return RebatesReport
     */
    const RebatesReport* GetRebatesReport() const;

    /**
     * @brief GetExpirationReport
     *  - Gets list of Member 's whose memberships expire on Date 's passed in
     * @param month - Date to find which Member 's expire that month
     * @return ExpirationReport
     */
    const ExpirationReport* GetExpirationReport(const Date& month) const;

    /**
     * @brief GetItemReport
     *  - Gles all information on Item passed in
     * @param item - Item to view
     * @return ItemReport
     */
    const ItemReport* GetItemReport(const Item& item) const;

    /**
     * @brief GetMemberPurchaseReport
     * @param id - Member ID to find purchases
     * @return
     */
    const MemberPurchaseReport* GetMemberPurchaseReport(int id) const;

    /**
     * @brief GetMemberPurchaseReport
     * @param name - name to find Member purchases
     * @return
     */
    const MemberPurchaseReport* GetMemberPurchaseReport(QString name) const;

    /**
     * @brief GetRegularConversionReport
     * - See which Regular Members should convert
     * @return
     */
    const RegularConversionReport* GetRegularConversionReport() const;\

    /**
     * @brief GetExecutiveConversionReport
     *  - See which Executive Members should convert
     * @return
     */
    const ExecutiveConversionReport* GetExecutiveConversionReport() const;
};

//Callback Functions
int getMemberCallback(void* mem, int colCount, char** results, char** colNames);



#endif /* DATABASE_H_ */
