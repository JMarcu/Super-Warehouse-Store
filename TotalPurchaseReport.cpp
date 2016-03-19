/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TotalPurchaseReport.h"

TotalPurchaseReport::TotalPurchaseReport(list<Member>* memList,
                                         list<Sale>*   saleList){
    list<Member>::iterator memIt  = memList->begin();
    list<Sale>::iterator   saleIt = saleList->begin();
    int index;
    list<Sale>* salePtr;
    purchases.resize(memList->size());
    
    index = 0;
    while(memIt != memList->end()){
        members.push_back(*memIt);
        totals.push_back(0);
        salePtr = new list<Sale>;
        
        while(memIt->GetID() == saleIt->GetMemberID()){
            salePtr->push_back(*saleIt);
            totals[index] += saleIt->GetSubtotal();
            
            saleIt++;
        }
        
        purchases.push_back(*salePtr);
        memIt++;
        index++;
    }
    
    memList->clear();
    saleList->clear();
    delete memList;
    delete saleList;
}

const Member& TotalPurchaseReport::GetMember (int index) const{
    return members[index];
}

const list<Sale>& TotalPurchaseReport::GetPurchases(int index) const{
    list<list<Sale> >::const_iterator it = purchases.begin();
    
    for(int i = 0; i < index; i++){
        it++;
    }
    
    return *it;
}

double TotalPurchaseReport::GetGrandTotal(int index) const{
    return totals[index];
}

int TotalPurchaseReport::GetMaxIndex() const{
    return members.size();
}