/*
 * ItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#include "ItemReport.h"

ItemReport::ItemReport(const list<Sale>& sales, const Item& i){
    item = i;
    
    quantity = 0;
    revenue  = 0;
        
    list<Sale>::const_iterator it = sales.begin();
    while(it != sales.end())
    {
        quantity++;
        revenue += it->GetSubtotal();
    }//END - (sales != item.begin())
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


