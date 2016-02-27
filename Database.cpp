/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Database.h"


Database::Database(){
    
    if(sqlite3_open("WarehouseDB.db3", &db) == SQLITE_OK){
        cout << "ALL GOOD";
    }
    else{
        cout << "NOT GOOD";
    }
    
    sqlite3_close(db);
}