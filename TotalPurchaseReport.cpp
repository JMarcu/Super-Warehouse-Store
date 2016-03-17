/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TotalPurchaseReport.h"

TotalPurchaseReport::TotalPurchaseReport(const list<Member>* memList,
                                         const list<Sale>*   saleList){
    list<Member>::const_iterator memIt  = memList->begin();
    list<Sale>::const_iterator   saleIt = saleList->begin();
    int index;
    
    index = 0;
    while(memIt != memList->end()){
        members[index] = *memIt;
        totals[index] = 0;
        
        while(memIt->GetID() == saleIt->GetMemberID()){
            purchases[index].push_back(*saleIt);
            totals[index] += saleIt->GetSubtotal();
            
            saleIt++;
        }
        
        memIt++;
        index++;
    }
}

const Member& TotalPurchaseReport::GetMember (int index){
    return members[index];
}

const list<Sale>& TotalPurchaseReport::GetPurchases(int index){
    return purchases[index];
}

double TotalPurchaseReport::GetGrandTotal(int index){
    return totals[index];
}