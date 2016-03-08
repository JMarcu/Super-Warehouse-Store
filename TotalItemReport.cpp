/*
 * TotalItemReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "TotalItemReport.h"

TotalItemReport::TotalItemReport()
{
	sales.clear();
}

TotalItemReport::TotalItemReport(list<Sale> soldIn)
{
	list<Sale>::iterator soldItems = soldIn.begin();

	while(soldItems != soldIn.end())
	{
		sales.push_back(*soldItems);
		soldItems++;
	}
}

TotalItemReport::~TotalItemReport()
{
	sales.clear();
}

