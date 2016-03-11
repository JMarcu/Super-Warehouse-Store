/*
 * DailySalesReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "DailySalesReport.h"

DailySalesReport::~DailySalesReport()
{
	salesList.clear();
	members.clear();
}



DailySalesReport::DailySalesReport(const list<Sale>&   salesListIn,
                                   const list<Member>& mems)
{
    members   = mems;
    salesList = salesListIn;
    
    list<Member>::const_iterator it = mems.begin();
    while(it != mems.end())
    {
        if(it->IsExecutive()){
            execCount++;
        }
        else{
            regCount++;
        }
    }
}

const list<Sale>& DailySalesReport::GetDailySales() const
{
	return salesList;
}

const list<Member>& DailySalesReport::GetAllMembers() const
{
	return members;
}

int DailySalesReport::GetRegularCount() const
{
	return regCount;
}

int DailySalesReport::GetExecutiveCount() const
{
	return execCount;
}


