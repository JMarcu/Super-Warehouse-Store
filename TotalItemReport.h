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
	TotalItemReport(list<Item>* i,
                        list<Sale>* sales);

	~TotalItemReport();

        const Item& GetItem(int index) const;
        int         GetQuantitySold(int index) const;
        double      GetRevenue(int index) const;
        int         ItemCount() const;
        
private:
    vector<Item>   items;
    vector<int>    quantitiesSold;
    vector<double> revenues;

};

#endif /* TOTALITEMREPORT_H_ */
