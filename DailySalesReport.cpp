/*
 * DailySalesReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "DailySalesReport.h"

/* Constructor - Reads in pointers to the lists of sales and members. Calculates
 * the regular and executive member counts from these lists.
 */
DailySalesReport::DailySalesReport(std::list<Sale>*   salesListIn,
                                   std::list<Member>* mems)
{
    members   = mems;
    salesList = salesListIn;
    
    execCount = 0;
    regCount = 0;
    
    std::list<Member>::iterator it = mems->begin();
    while(it != mems->end())
    {
        if(it->IsExecutive()){
            execCount++;
        }
        else{
            regCount++;
        }

        it++;
    }
}

//Destructor - Clears and deletes the lists.
DailySalesReport::~DailySalesReport()
{
    salesList->clear();
    members->clear();
    
    delete salesList;
    delete members;
}

const std::list<Sale>& DailySalesReport::GetDailySales() const
{
    return *salesList;
}

const std::list<Member>& DailySalesReport::GetAllMembers() const
{
	return *members;
}

int DailySalesReport::GetRegularCount() const
{
	return regCount;
}

int DailySalesReport::GetExecutiveCount() const
{
	return execCount;
}


