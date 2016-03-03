/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Database.h"

Database::Database(string name){    
    sqlite3_open(name.c_str(), &db);
}

Database::~Database(){
    sqlite3_close(db);
}

void Database::AddMember(const RegularMember& member){
    char* errMsg;
    ostringstream sqlCmmd;
    sqlCmmd << "INSERT INTO Members (id, name, expiration, total_spent) "
            << "VALUES (" << member.GetNumber() << ", "
                          << member.GetMember() << ", "
                          << member.GetExpiration() << ", "
                          << member.GetTotalSpent() << ");";

    sqlite3_exec(db, sqlCmmd.str().c_str(), NULL, 0, &errMsg);
    
    if(errMsg != NULL){
        cerr << errMsg;
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
