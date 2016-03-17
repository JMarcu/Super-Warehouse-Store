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

class TotalItemReport
{
public:
	TotalItemReport(const list<Item>* i,
                        const list<Sale>* sales);

	~TotalItemReport();

        const Item& GetItem(int index) const;
        int         GetQuantitySold(int index) const;
        double      GetRevenue(int index) const;
        
private:
    vector<Item>   items;
    vector<int>    quantitiesSold;
    vector<double> revenues;

};

#endif /* TOTALITEMREPORT_H_ */
