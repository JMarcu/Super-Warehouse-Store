/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TotalPurchaseReport.h
 * Author: james
 *
 * Created on March 8, 2016, 6:30 PM
 */

#ifndef TOTALPURCHASEREPORT_H
#define TOTALPURCHASEREPORT_H

#include "Member.h"
#include "Sale.h"

#include <list>
#include <vector>

using namespace std;

class TotalPurchaseReport{
private: 
    vector<Member>      members;
    vector<list<Sale> > purchases;
    vector<double>      totals;

public:
    TotalPurchaseReport(const list<Member>* memList,
                        const list<Sale>*   saleList);
    
    const Member& GetMember    (int index);
    const list<Sale>& GetPurchases (int index);
    double GetGrandTotal(int index);
};
    

#endif /* TOTALPURCHASEREPORT_H */

