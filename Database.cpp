/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Database.h"
#include "ItemReport.h"
#include <stdlib.h>
#include <iostream>

Database::Database(string name){    
    sqlite3_open(name.c_str(), &db);
}

Database::~Database(){
    sqlite3_close(db);
}

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

Member* Database::GetMember(QString name) const{
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE name=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_bind_text(stmt, 1, name.toStdString().c_str(), strlen(name.toStdString().c_str()), NULL);
    
    rc = sqlite3_step(stmt);
    
    int id = sqlite3_column_int(stmt, 0);
    double tot = sqlite3_column_double(stmt, 3);
    Date exp(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2)))); 
    bool isEx = sqlite3_column_int (stmt, 4);
    
    return new Member(name, id, tot, exp, isEx);
}

list<Member>* Database::GetAllMembers() const{
    list<Member>* members = new list<Member>;
    
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

list<Member>* Database::GetRegularMembers() const{
    list<Member>* members = new list<Member>;
    
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

list<Member>* Database::GetExecutiveMembers() const{
    list<Member>* members = new list<Member>;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE is_executive=1 ORDER BY id;";
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

list<Sale>* Database::GetSales(Date day) const{
    list<Sale>* sales = new list<Sale>;
    Sale* salePtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales WHERE order_date=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);

    const char* dayStr = day.toString().toStdString().c_str();
    
    rc = sqlite3_bind_text(stmt, 1, dayStr, strlen(dayStr), NULL);
    
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

list<Sale>* Database::GetSales(const Item& item) const{
    list<Sale>* sales = new list<Sale>;
    Sale* salePtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales WHERE item_name=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);

    const char* dayStr = item.GetItem().toStdString().c_str();
    
    rc = sqlite3_bind_text(stmt, 1, dayStr, strlen(dayStr), NULL);
    
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

list<Sale>* Database::GetSales(const Member& member) const{
        list<Sale>* sales = new list<Sale>;
    Sale* salePtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales WHERE member_id=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_bind_int(stmt, 1, member.GetID());
    
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

list<Sale>* Database::GetAllSales() const{
    list<Sale>* sales = new list<Sale>;
    Sale* salePtr;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Sales";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    
    while(rc != SQLITE_DONE){
        salePtr = new Sale(
            sqlite3_column_int(stmt, 1),
            QString(static_cast<const char*>(sqlite3_column_blob(stmt, 2))),
            sqlite3_column_int(stmt, 3),
            sqlite3_column_double(stmt, 4),
            Date(QString(static_cast<const char*>(sqlite3_column_blob(stmt, 5))))
        );
        
        sales->push_back(*salePtr);
        
        rc = sqlite3_step(stmt);
    }
    
    return sales;
}

list<Item>* Database::GetAllItems() const{
    list<Item>* items = new list<Item>;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Items ORDER BY name";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_step(stmt);
    
    while(rc != SQLITE_DONE){
        items->push_back(Item(QString::fromStdString(string(static_cast<const char*>(sqlite3_column_blob(stmt, 0)), sqlite3_column_bytes(stmt, 0))),
                sqlite3_column_double(stmt, 1),
                sqlite3_column_int(stmt, 2)
                ));
        
        rc = sqlite3_step(stmt);
    }
    
    return items;
}

void Database::AddMember(const RegularMember& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Members (id, name, expiration, total_spent, is_executive) "
            << "VALUES (" << member.GetNumber()                << ", "
                          << "'" << member.GetMember() << "'"  << ", "
                          << "'" << member.GetExpiration().toString().toStdString() << "'" << ", "
                          << member.GetTotalSpent()            << ", " 
                          << "'false'"
            << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}

void Database::AddMember(const ExecutiveMember& member){
    const RegularMember* mem = &member;
    AddMember(*mem);
    
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "UPDATE Members SET is_executive='true', "
                               << "rebate = " << member.GetRebate() << " "
            << "WHERE id=" << member.GetNumber();
    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}

void Database::DeleteMember(const RegularMember& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "DELETE FROM Members WHERE (rowid = " << member.GetNumber() << ")";
    
    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg;
    }
}

void Database::DeleteMember(const ExecutiveMember& member){
    const RegularMember* mem = &member;
    DeleteMember(*mem);
}

void Database::AddItem(const Item& item){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Items (name, price, quantity) "
            << "VALUES (" << "'" << item.GetItem().toStdString() << "', "
                          <<        item.GetPrice()  << ", "
                          <<        item.GetAmount() 
            << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}

void Database::DeleteItem(const Item& item){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "DELETE FROM Items WHERE (name = " << item.GetItem().toStdString() << ")";
    
    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg;
    }
}

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

const DailySalesReport* Database::GetDailySalesReport(Date day) const{
    list<Sale>*   sales;
    sales = GetSales(day);
    list<Member> members;
    Member* mem;
    
    list<Sale>::iterator it = sales->begin();
    while(it != sales->end()){
        mem = GetMember(it->GetMemberID());
        members.push_back(*mem);
        it++;
    }
    
    return new DailySalesReport(*sales, members);
}

const TotalPurchaseReport* Database::GetTotalPurchaseReport() const{
    return new TotalPurchaseReport(GetExecutiveMembers(), GetAllSales());
}

const TotalItemReport* Database::GetTotalItemReport() const{
    list<Sale>* sales;
    sales = GetAllSales();
    
    list<Item>* items;
    items = GetAllItems();
    
    return new TotalItemReport(items, sales);
}

const RebatesReport* Database::GetRebatesReport() const{
    return new RebatesReport(GetExecutiveMembers());
}

const ExpirationReport* Database::GetExpirationReport(Date month) const{
    list<Member>* members = new list<Member>;
    
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

const ItemReport* Database::GetItemReport(const Item& item) const{
    list<Sale>* sales;
    sales = GetSales(item);
    return new ItemReport(*sales, item);
}

const MemberPurchaseReport* Database::GetMemberPurchaseReport(int id) const{
    Member* member;
    member = GetMember(id);
    
    list<Sale>* sales;
    sales = GetSales(*member);
    
    return new MemberPurchaseReport(member, sales);
}

const MemberPurchaseReport* Database::GetMemberPurchaseReport(QString name) const{
    Member* member;
    member = GetMember(name);
    
    list<Sale>* sales;
    sales = GetSales(*member);
    
    return new MemberPurchaseReport(member, sales);
}

const RegularConversionReport* Database::GetRegularConversionReport() const{
    return new RegularConversionReport(GetRegularMembers());
}

const ExecutiveConversionReport* Database::GetExecutiveConversionReport() const{
    return new ExecutiveConversionReport(GetExecutiveMembers());
}