/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: james
 *
 * Created on February 27, 2016, 2:00 AM
 */

#include <cstdlib>
#include "Database.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Database db("WarehouseDB.db3");
    ExecutiveMember memE("John", 123, 1, 1, 1990, 1000, 300);
    RegularMember memR("Jack", 234, 4000, 2, 2, 1995);
    
    
    return 0;
}

