/*
 * DailySalesReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "DailySalesReport.h"

DailySalesReport::DailySalesReport()
{
	salesList.clear();
	allMembers.clear();
}

DailySalesReport::~DailySalesReport()
{
	salesList.clear();
	allMembers.clear();
}



DailySalesReport::DailySalesReport( list<Sale> 			  salesListIn,
								    list<RegularMember>   regularMembersIn,
								    list<ExecutiveMember> execMembersIn)
{
	//PROCESSING - creates list iterators to access the information in
	//				the lists passed in
	list<RegularMember>::iterator   regular   = regularMembersIn.begin();
	list<ExecutiveMember>::iterator executive = execMembersIn.begin();
	list<Sale>::iterator 			sales     = salesListIn.begin();


	//PROCESSING - pushes an executive member or regular member to the
	//				all members lists in alphabetical order
	while(regular != regularMembersIn.end() || executive != execMembersIn.end())
	{
		//PROCESSING - checks to see which member should be added to the list
		//				in alphabetical order
		if(regular->GetMember().compare(executive->GetMember())  < 0)
		{
			allMembers.push_back(*regular);
			regular++;
		}
		else
		{
			allMembers.push_back((RegularMember)*executive);
			executive++;
		}

	}//END - while(regular != regularMembers.end() || executive != execMembers.end())


	salesList = salesListIn;

}//END - DailySalesReport


list<Sale> DailySalesReport::GetDailySales() const
{
	return salesList;
}

list<RegularMember> DailySalesReport::GetAllMembers() const
{
	return allMembers;
}

int DailySalesReport::GetRegularCount(list<RegularMember> regularMembers) const
{
	return regularMembers.size();
}

int DailySalesReport::GetExecutiveCount(list<ExecutiveMember> execMembers) const
{
	return execMembers.size();
}


