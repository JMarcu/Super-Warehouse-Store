/*
 * TotalItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "TotalItemReport.h"

TotalItemReport::TotalItemReport(std::list<Item>* i,
                                 std::list<Sale>* sales){
    items.resize(i->size());
    quantitiesSold.resize(i->size());
    revenues.resize(i->size());
    
    std::list<Item>::const_iterator itemIt = i->begin();
    std::list<Sale>::const_iterator saleIt;
    int index = 0;
    
    while(itemIt != i->end()){
        items[index] = *itemIt;
        quantitiesSold[index] = 0;
        revenues[index]       = 0;
        saleIt = sales->begin();
        
        while(saleIt != sales->end()){
            if(saleIt->GetItemName() == itemIt->GetItem()){
                quantitiesSold[index] += saleIt->GetQuantityPurchased();
                revenues[index] += saleIt->GetSubtotal();               
            }
            
            saleIt++;
        }
        
        itemIt++;
        index++;
    }
    
    i->clear();
    sales->clear();
    delete i;
    delete sales;
}

TotalItemReport::~TotalItemReport(){
    items.clear();
    quantitiesSold.clear();
    revenues.clear();
}

const Item& TotalItemReport::GetItem(int index) const{
    if(index < ItemCount()){
        return items[index];
    }
    else{
        //throw new out_of_range("Index out of range when accessing TotalItemReport.");
    }
}

int TotalItemReport::GetQuantitySold(int index) const{
    if(index < ItemCount()){
        return quantitiesSold[index];
    }
    else{
        //throw new out_of_range("Index out of range when accessing TotalItemReport.");
    }
}

double TotalItemReport::GetRevenue(int index) const{
    if(index < ItemCount()){
        return revenues[index];
    }
    else{
        //throw new out_of_range("Index out of range when accessing TotalItemReport.");
    }
}

int TotalItemReport::ItemCount() const{
    return items.size();
}
