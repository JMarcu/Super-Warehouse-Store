/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Database.h"
#include "ItemReport.h"
#include <stdlib.h>
#include <iostream>
#include <QDebug>

/**
 * @brief Database::Database
 * @param name
 */
Database::Database(string name){    
    sqlite3_open(name.c_str(), &db);
}

/**
 * @brief Database::~Database
 */
Database::~Database(){
    sqlite3_close(db);
}

/**
 * @brief Database::GetMember
 * @param id
 * @return
 */
Member* Database::GetMember(int id) const{
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE id=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_bind_int(stmt, 1, id);
    
    rc = sqlite3_step(stmt);
    
    QString name = QString(static_cast<const char*>(sqlite3_column_blob(stmt, 1)));
    double tot = sqlite3_column_double(stmt, 3);
    Date exp(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))); 
    bool isEx = sqlite3_column_int (stmt, 4);
    
    return new Member(name, id, tot, exp, isEx);
}

/**
 * @brief Database::GetMember
 * @param name
 * @return
 */
Member* Database::GetMember(QString name) const{
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE name='"
            << name.toStdString() << "';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    
    int id = sqlite3_column_int(stmt, 0);
    double tot = sqlite3_column_double(stmt, 3);
    Date exp(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))); 
    bool isEx = sqlite3_column_int (stmt, 4);
    
    return new Member(name, id, tot, exp, isEx);
}

/**
 * @brief Database::GetAllMembers
 * @return
 */
std::list<Member>* Database::GetAllMembers() const{
    std::list<Member>* members = new std::list<Member>;
    

    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members ORDER BY id;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    while(rc != SQLITE_DONE){
        members->push_back(Member(
                QString(static_cast<const char*>(sqlite3_column_blob(stmt, 1))),
                sqlite3_column_int(stmt, 0),
                sqlite3_column_double(stmt, 3),
                Date(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))),
                sqlite3_column_int (stmt, 4)
                ));
        


        rc = sqlite3_step(stmt);

    }

    return members;
}

/**
 * @brief Database::GetRegularMembers
 * @return
 */
std::list<Member>* Database::GetRegularMembers() const{
   std::list<Member>* members = new std::list<Member>;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE is_executive=0 ORDER BY id;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    while(rc != SQLITE_DONE){
        members->push_back(Member(
                QString(static_cast<const char*>(sqlite3_column_blob(stmt, 1))),
                sqlite3_column_int(stmt, 0),
                sqlite3_column_double(stmt, 3),
                Date(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))),
                sqlite3_column_int (stmt, 4)
                ));
        
        rc = sqlite3_step(stmt);
    }
    
    return members;
}

/**
 * @brief Database::GetExecutiveMembers
 * @return
 */
std::list<Member>* Database::GetExecutiveMembers() const{
    std::list<Member>* members = new std::list<Member>;
    Member* memPtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE is_executive=1 ORDER BY id;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    while(rc != SQLITE_DONE){

        memPtr = new Member(
                QString(static_cast<const char*>(sqlite3_column_blob(stmt, 1))),
                sqlite3_column_int(stmt, 0),
                sqlite3_column_double(stmt, 3),
                Date(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))),
                sqlite3_column_int (stmt, 4)
            );
        
        members->push_back(*memPtr);

        memPtr->GetName();
        delete memPtr;
        
        rc = sqlite3_step(stmt);
    }
    
    return members;
}

/**
 * @brief Database::GetSales
 * @param day
 * @return
 */
std::list<Sale>* Database::GetSales(Date day) const{
    std::list<Sale>* sales = new std::list<Sale>;
    Sale* salePtr;

    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales WHERE order_date='"
            << day.toString().toStdString() 
            << "' ORDER BY member_id, item_name;";
    sqlite3_stmt* stmt;
    cout << sqlCmmd.str() << endl;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);


    while(rc != SQLITE_DONE){
        
        salePtr = new Sale(
            sqlite3_column_int(stmt, 0),
            QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 1)), sqlite3_column_bytes(stmt, 1))),
            sqlite3_column_int(stmt, 2),
            sqlite3_column_double(stmt, 3),
            Date(QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 4)), sqlite3_column_bytes(stmt, 4))))
        );
        
        sales->push_back(*salePtr);


        rc = sqlite3_step(stmt);
    }


    return sales;
}

/**
 * @brief Database::GetSales
 * @param item
 * @return
 */

std::list<Sale>* Database::GetSales(const Item& item) const{
    std::list<Sale>* sales = new std::list<Sale>;
    Sale* salePtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales WHERE item_name='"
            << item.GetItem().toStdString() << "';";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
 
    while(rc != SQLITE_DONE){
        
        salePtr = new Sale(
            sqlite3_column_int(stmt, 0),
            QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 1)), sqlite3_column_bytes(stmt, 1))),
            sqlite3_column_int(stmt, 2),
            sqlite3_column_double(stmt, 3),
            Date(QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 4)), sqlite3_column_bytes(stmt, 4))))
        );
        
        sales->push_back(*salePtr);
        delete salePtr;
        
        rc = sqlite3_step(stmt);
    }
    
    return sales;
}


/**
 * @brief Database::GetSales
 * @param member
 * @return
 */
std::list<Sale>* Database::GetSales(const Member& member) const{
        std::list<Sale>* sales = new std::list<Sale>;
    Sale* salePtr;

    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales WHERE member_id=? ORDER BY item_name;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_bind_int(stmt, 1, member.GetID());
    
    rc = sqlite3_step(stmt);
    
    while(rc != SQLITE_DONE)
    {
           salePtr = new Sale(
            sqlite3_column_int(stmt, 0),
            QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 1)), sqlite3_column_bytes(stmt, 1))),
            sqlite3_column_int(stmt, 2),
            sqlite3_column_double(stmt, 3),
            Date(QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 4)), sqlite3_column_bytes(stmt, 4))))
        );
        
        sales->push_back(*salePtr);
        
        rc = sqlite3_step(stmt);
    }
    
    return sales;
}

/**
 * @brief Database::GetAllSales
 * @return
 */
std::list<Sale>* Database::GetAllSales() const{
    std::list<Sale>* sales = new std::list<Sale>;
    Sale* salePtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales ORDER BY member_id";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    
    while(rc != SQLITE_DONE){
        salePtr = new Sale(
            sqlite3_column_int(stmt, 0),
            QString(static_cast<const char*>(sqlite3_column_blob(stmt, 1))),
            sqlite3_column_int(stmt, 2),
            sqlite3_column_double(stmt, 3),
            Date(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 4))))
        );

        sales->push_back(*salePtr);
        delete salePtr;
     
        rc = sqlite3_step(stmt);
    }

    return sales;
}


/**
 * @brief Database::GetAllItems
 * @return
 */
std::list<Item>* Database::GetAllItems() const{
    std::list<Item>* items = new std::list<Item>;
    Item* itemPtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Items ORDER BY name";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    
    while(rc != SQLITE_DONE){
        itemPtr = new Item(QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 0)), sqlite3_column_bytes(stmt, 0))),
            sqlite3_column_double(stmt, 1));
        
        items->push_back(*itemPtr);
        delete itemPtr;
        
        rc = sqlite3_step(stmt);
    }
    
    return items;
}


/**
 * @brief Database::AddMember
 * @param member
 */
void Database::AddMember(const Member& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Members (id, name, expiration, total_spent, is_executive) "
            << "VALUES (" << member.GetID() << ", "
                          << "'" << member.GetName().toStdString() << "'"  << ", "
                          << "'" << member.GetExpiration().toString().toStdString() << "'" << ", "
                          << member.GetTotalSpent() << ", " 
                          << member.IsExecutive() 
            << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}


/**
 * @brief Database::DeleteMember
 * @param member
 */
void Database::DeleteMember(const Member& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "DELETE FROM Members WHERE (id = " << member.GetID() << ")";
    
    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg;
    }
}


/**
 * @brief Database::UpdateMember
 * @param member
 */
void Database::UpdateMember(const Member& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "UPDATE Members SET "
                << "name='" << member.GetName().toStdString() << "', "
                << "expiration='" << member.GetExpiration().toString().toStdString().c_str() << "', "
                << "total_spent=" << member.GetTotalSpent() << ", "
                << "is_executive=" << (member.IsExecutive() ? 1 : 0) << " "
            << "WHERE id = " << member.GetID() << ";";
    
    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg;
    }
}


/**
 * @brief Database::AddItem
 * @param item
 */
void Database::AddItem(const Item& item){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Items (name, price) "
            << "VALUES (" << "'" << item.GetItem().toStdString() << "', "
                          <<        item.GetPrice()
            << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}


/**
 * @brief Database::UpdateItem
 * @param item
 */
void Database::UpdateItem(const Item& item){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "UPDATE Items SET "
                << "price=" << item.GetPrice() << " "
            << "WHERE name = '" << item.GetItem().toStdString() << "';";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);

    if(errMsg != NULL){
        cerr << errMsg;
    }
}


/**
 * @brief Database::DeleteItem
 * @param item
 */
void Database::DeleteItem(const Item& item){
    char* errMsg;
    ostringstream sqlCmmd;

    qDebug() << item.GetItem();

    sqlCmmd << "DELETE FROM Items WHERE (name = '" << item.GetItem().toStdString() << "')";
    
    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);

    if(errMsg != NULL)
    {
        qDebug() << "Error message";
        cerr << errMsg;
    }
}

/**
 * @brief Database::AddSale
 * @param sale
 */

void Database::AddSale(const Sale& sale){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Sales (member_id, item_name, quantity_purchased, total_cost, order_date) "
            << "VALUES (" << sale.GetMemberID() << ", "
                          << "'" << sale.GetItemName().toStdString() << "', "
                          << sale.GetQuantityPurchased() << ", "
                          << sale.GetSubtotal() << ", "
                          << "'" << sale.GetOrderDate().toString().toStdString() << "'" 
            << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}


/**
 * @brief Database::GetDailySalesReport
 * @param day
 * @param memType
 * @return
 */
const DailySalesReport* Database::GetDailySalesReport(Date day, int memType) const{
    std::list<Sale>*   sales;


    sales = GetSales(day);

    std::list<Member>* members = new std::list<Member>;
    Member* mem;
    
    std::list<Sale>::iterator it = sales->begin();

    while(it != sales->end()){

        mem = GetMember(it->GetMemberID());

        if( memType == 0                         ||
           (memType >  0 &&  mem->IsExecutive()) || 
           (memType <  0 && !mem->IsExecutive()) 
          ){
            members->push_back(*mem);

        }
        
        members->unique();
        delete mem;
        it++;
    }
    
    return new DailySalesReport(sales, members);
}


/**
 * @brief Database::GetTotalPurchaseReport
 * @return
 */
const TotalPurchaseReport* Database::GetTotalPurchaseReport() const{
    return new TotalPurchaseReport(GetAllMembers(), GetAllSales());
}


/**
 * @brief Database::GetTotalItemReport
 * @return
 */
const TotalItemReport* Database::GetTotalItemReport() const{
    std::list<Sale>* sales;
    sales = GetAllSales();
    
    std::list<Item>* items;
    items = GetAllItems();
    
    return new TotalItemReport(items, sales);
}


/**
 * @brief Database::GetRebatesReport
 * @return
 */
const RebatesReport* Database::GetRebatesReport() const{
    return new RebatesReport(GetExecutiveMembers());
}

/**
 * @brief Database::GetExpirationReport
 * @param month
 * @return
 */
const ExpirationReport* Database::GetExpirationReport(const Date& month) const{
    std::list<Member>* members = new std::list<Member>;

    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE substr(expiration, 1, 7)=? ORDER BY id;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    string dateStr = month.toString().toStdString().substr(0, 7);
    
    rc = sqlite3_bind_text(stmt, 1, dateStr.c_str(), strlen(dateStr.c_str()), NULL);
    
    rc = sqlite3_step(stmt);

    while(rc != SQLITE_DONE){

        members->push_back(Member(
                QString(static_cast<const char*>(sqlite3_column_blob(stmt, 1))),
                sqlite3_column_int(stmt, 0),
                sqlite3_column_double(stmt, 3),
                Date(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))),
                sqlite3_column_int (stmt, 4)
                ));
        
        rc = sqlite3_step(stmt);
    }
    
    return new ExpirationReport(month, members);
}


/**
 * @brief Database::GetItemReport
 * @param item
 * @return
 */
const ItemReport* Database::GetItemReport(const Item& item) const{
    return new ItemReport(GetSales(item), item);
}

/**
 * @brief Database::GetMemberPurchaseReport
 * @param id
 * @return
 */
const MemberPurchaseReport* Database::GetMemberPurchaseReport(int id) const{
    Member* member;
    member = GetMember(id);
    
    std::list<Sale>* sales;
    sales = GetSales(*member);
    
    return new MemberPurchaseReport(member, sales);
}

/**
 * @brief Database::GetMemberPurchaseReport
 * @param name
 * @return
 */
const MemberPurchaseReport* Database::GetMemberPurchaseReport(QString name) const{
    Member* member;
    member = GetMember(name);
    
    std::list<Sale>* sales;
    sales = GetSales(*member);
    
    return new MemberPurchaseReport(member, sales);
}


/**
 * @brief Database::GetRegularConversionReport
 * @return
 */
const RegularConversionReport* Database::GetRegularConversionReport() const{
    return new RegularConversionReport(GetRegularMembers());
}

/**
 * @brief Database::GetExecutiveConversionReport
 * @return
 */
const ExecutiveConversionReport* Database::GetExecutiveConversionReport() const{
    return new ExecutiveConversionReport(GetExecutiveMembers());
}
