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

/* A user of your program should be able to enter an item name and get the 
quantity of that item sold as well as the total revenue for the item.*/
class ItemReport
{
public:
    /**
     * @brief ItemReport
     * @param sales
     * @param i
     */
    ItemReport(std::list<Sale>* sales, const Item& i);

    /**
     * @brief GetItem
     * @return
     */
    const Item& GetItem()     const;
    /**
     * @brief GetQuantitySold
     * @return
     */
    int     GetQuantitySold() const;
    /**
     * @brief GetTotalRevenue
     * @return
     */
    double  GetTotalRevenue() const;

private:
    Item   item;
    int    quantity;
    double revenue;
};

#endif /* ITEMREPORT_H_ */
