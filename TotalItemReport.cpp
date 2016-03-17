/*
 * TotalItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "TotalItemReport.h"

TotalItemReport::TotalItemReport(const list<Item>* i,
                                 const list<Sale>* sales){
    list<Item>::const_iterator itemIt = i->begin();
    list<Sale>::const_iterator saleIt = sales->begin();
    int index = 0;
    
    while(itemIt != i->end()){
        items.push_back(*itemIt);
        
        quantitiesSold[index] = 0;
        revenues[index] = 0;
        while(saleIt->GetItemName() == itemIt->GetItem()){
            quantitiesSold[index] += saleIt->GetQuantityPurchased();
            revenues[index] += saleIt->GetSubtotal();
            
            saleIt++;
        }
        
        itemIt++;
        index++;
    }
}

TotalItemReport::~TotalItemReport(){
    items.clear();
    quantitiesSold.clear();
    revenues.clear();
}

const Item& TotalItemReport::GetItem(int index) const{
    return items[index];
}

int TotalItemReport::GetQuantitySold(int index) const{
    return quantitiesSold[index];
}

double TotalItemReport::GetRevenue(int index) const{
    return revenues[index];
}

