/*
 * TotalItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "TotalItemReport.h"

/**
 * @brief TotalItemReport::TotalItemReport
 * @param i
 * @param sales
 */
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

/**
 * @brief TotalItemReport::~TotalItemReport
 */
TotalItemReport::~TotalItemReport(){
    items.clear();
    quantitiesSold.clear();
    revenues.clear();
}

/**
 * @brief TotalItemReport::GetItem
 * @param index
 * @return
 */
const Item& TotalItemReport::GetItem(int index) const{
    if(index < ItemCount()){
        return items[index];
    }
    else{
        //throw new out_of_range("Index out of range when accessing TotalItemReport.");
    }
}

/**
 * @brief TotalItemReport::GetQuantitySold
 * @param index
 * @return
 */
int TotalItemReport::GetQuantitySold(int index) const{
    if(index < ItemCount()){
        return quantitiesSold[index];
    }
    else{
        //throw new out_of_range("Index out of range when accessing TotalItemReport.");
    }
}

/**
 * @brief TotalItemReport::GetRevenue
 * @param index
 * @return
 */
double TotalItemReport::GetRevenue(int index) const{
    if(index < ItemCount()){
        return revenues[index];
    }
    else{
        //throw new out_of_range("Index out of range when accessing TotalItemReport.");
    }
}

/**
 * @brief TotalItemReport::ItemCount
 * @return
 */
int TotalItemReport::ItemCount() const{
    return items.size();
}
