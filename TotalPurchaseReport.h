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

/*A report that prints the total purchases for all members sorted
by membership number. It should also include a grand total of
the purchases.*/
class TotalPurchaseReport{
private: 
    vector<Member>      members;
    list<list<Sale> > purchases;
    vector<double>      totals;

public:
    TotalPurchaseReport(list<Member>* memList,
                        list<Sale>*   saleList);
    
    const Member& GetMember (int index) const;
    const list<Sale>& GetPurchases (int index) const;
    double GetGrandTotal(int index) const;
    int GetMaxIndex() const;
};
    

#endif /* TOTALPURCHASEREPORT_H */

