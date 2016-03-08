/*
 * ItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#include "ItemReport.h"

ItemReport::ItemReport()
{
	totalSales.clear();
}

ItemReport::ItemReport(list<Sale> item, string itemName)
{
	list<Sale>::iterator sales = item.begin();

	while(sales != item.end())
	{
		if(itemName == sales->GetItemName())
		{
			totalSales.push_back(*sales);
		}
		sales++;
	}//END - (sales != item.begin())
}

ItemReport::~ItemReport()
{
	totalSales.clear();
}

list<Sale> ItemReport::GetTotalSales() const
{
	return totalSales;
}



