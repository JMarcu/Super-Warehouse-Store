/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TotalPurchaseReport.h"
#include <qDebug>

/**
 * @brief TotalPurchaseReport::TotalPurchaseReport
 * @param memList
 * @param saleList
 */
TotalPurchaseReport::TotalPurchaseReport(std::list<Member>* memList,
                                         std::list<Sale>*   saleList){
    std::list<Member>::const_iterator memIt  = memList->begin();
    std::list<Sale>::const_iterator   saleIt = saleList->begin();
    int index;
    std::list<Sale>* salePtr;

//    totals.resize(memList->size());
//    purchases.resize(memList->size());
//    members.resize(memList->size());
    
    index = 0;
    while(memIt != memList->end())
    {
        members.push_back(*memIt);
        totals.push_back(0);

        salePtr = new list<Sale>;


        while(memIt->GetID() == saleIt->GetMemberID()){

            salePtr->push_back(*saleIt);
            totals[index] += saleIt->GetSubtotal();
            
            saleIt++;
        }
        
        purchases.push_back(salePtr);
        memIt++;
        index++;
    }
    
    memList->clear();
    saleList->clear();


    delete memList;
    delete saleList;

}

/**
 * @brief TotalPurchaseReport::GetMember
 * @param index
 * @return
 */
const Member& TotalPurchaseReport::GetMember (int index) const{
    return members[index];
}

/**
 * @brief TotalPurchaseReport::GetPurchases
 * @param index
 * @return
 */
const std::list<Sale>& TotalPurchaseReport::GetPurchases(int index) const{
    return *purchases[index];
}

/**
 * @brief TotalPurchaseReport::GetGrandTotal
 * @param index
 * @return
 */
double TotalPurchaseReport::GetGrandTotal(int index) const{
    return totals[index];
}

/**
 * @brief TotalPurchaseReport::GetMaxIndex
 * @return
 */
int TotalPurchaseReport::GetMaxIndex() const{
    return members.size() - 1;
}
