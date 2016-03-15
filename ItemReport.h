/*
 * ItemReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#ifndef ITEMREPORT_H_
#define ITEMREPORT_H_

#include "Sale.h"
#include "Items.h"
#include <sstream>
#include <list>

class ItemReport
{
public:
    ItemReport(const list<Sale>& sales, const Item& i);

    const Item& GetItem()     const;
    int     GetQuantitySold() const;
    double  GetTotalRevenue() const;

private:
    Item   item;
    int    quantity;
    double revenue;
};

#endif /* ITEMREPORT_H_ */
