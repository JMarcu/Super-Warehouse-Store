/*
 * ItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#include "ItemReport.h"

ItemReport::ItemReport(std::list<Sale>* sales, const Item& i){
    item = i;
    
    quantity = 0;
    revenue  = 0;
        
    std::list<Sale>::iterator it = sales->begin();
    while(it != sales->end())
    {
        quantity += it->GetQuantityPurchased();
        revenue  += it->GetSubtotal();
        
        it++;
    }//END - (sales != item.begin())
    
    sales->clear();
    delete sales;
}

const Item& ItemReport::GetItem() const
{
    return item;
}

int ItemReport::GetQuantitySold() const{
    return quantity;
}

double ItemReport::GetTotalRevenue() const{
    return revenue;
}


