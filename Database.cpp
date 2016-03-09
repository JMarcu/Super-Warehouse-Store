/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Database.h"
#include <stdlib.h>
#include <iostream>

Database::Database(string name){    
    sqlite3_open(name.c_str(), &db);
}

Database::~Database(){
    sqlite3_close(db);
}

Member& Database::getMember(int id){
    Member* mem;
    int (*callback) (void*, int, char**, char**) = &getMemberCallback;
    
    ostringstream sqlCmmd;
    sqlCmmd << "SELECT * FROM Members WHERE id=?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sqlCmmd.str().c_str(), -1, &stmt, NULL);
    
    rc = sqlite3_bind_int(stmt, 1, id);
    
    rc = sqlite3_step(stmt);
    
    string name = string(static_cast<const char*>(sqlite3_column_blob(stmt, 1)),
                         sqlite3_column_bytes(stmt, 1));
    int test = sqlite3_column_int(stmt, 0);
    double tot = sqlite3_column_double(stmt, 3);
    Date exp(string(static_cast<const char*>(sqlite3_column_blob(stmt, 2)),
                    sqlite3_column_bytes(stmt, 2)
                   )
            ); 
    bool isEx = sqlite3_column_int (stmt, 4);
    
    mem = new Member(name, id, tot, exp, isEx);
    
    cout << endl;
    cout << mem->GetName() << endl;
    cout << mem->GetID() << endl;
    cout << mem->GetExpiration().toString() << endl;
    cout << mem->GetTotalSpent() << endl;
    cout << mem->GetRebate() << endl;
    
    return *mem;
}

void Database::AddMember(const RegularMember& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Members (id, name, expiration, total_spent, is_executive) "
            << "VALUES (" << member.GetNumber()                << ", "
                          << "'" << member.GetMember() << "'"  << ", "
                          << "'" << member.GetExpiration().toString() << "'" << ", "
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
            << "VALUES (" << "'" << item.GetItem()   << "', "
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
    sqlCmmd << "DELETE FROM Items WHERE (name = " << item.GetItem() << ")";
    
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
                          << "'" << sale.GetItemName() << "', "
                          << sale.GetQuantityPurchased() << ", "
                          << sale.GetTotalCost() << ", "
                          << "'" << sale.GetOrderDate().toString() << "'" 
            << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg << endl;
    }
}