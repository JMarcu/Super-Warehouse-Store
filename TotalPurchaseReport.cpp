/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TotalPurchaseReport.h"

TotalPurchaseReport::TotalPurchaseReport(list<Sale> sales){
    list<Sale>::iterator it = sales.begin();
    
    while(it != sales.end()){
        allMembers.push_back(it->GetMemberID()))
    }
}

Member     getMember    (int index);
list<Sale> getPurchases (int index);
double     getGrandTotal(int index);