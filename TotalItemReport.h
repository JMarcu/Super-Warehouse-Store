/*
 * TotalItemReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#ifndef TOTALITEMREPORT_H_
#define TOTALITEMREPORT_H_

#include "Sale.h"
#include "Items.h"
#include <list>
#include <vector>

/*A report that prints out the quantity of each item sold sorted
by item name and the total revenue for each item.*/

class TotalItemReport
{
public:
    /**
     * @brief TotalItemReport
     * @param i
     * @param sales
     */
    TotalItemReport(std::list<Item>* i,
                        std::list<Sale>* sales);

	~TotalItemReport();

    /**
     * @brief GetItem
     * @param index
     * @return
     */
    const Item& GetItem(int index) const;

    /**
     * @brief GetQuantitySold
     * @param index
     * @return
     */
    int GetQuantitySold(int index) const;

    /**
     * @brief GetRevenue
     * @param index
     * @return
     */
    double GetRevenue(int index) const;

    /**
     * @brief ItemCount
     * @return
     */
    int ItemCount() const;
        
private:
    vector<Item>   items;
    vector<int>    quantitiesSold;
    vector<double> revenues;

};

#endif /* TOTALITEMREPORT_H_ */
