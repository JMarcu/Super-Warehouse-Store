/*
 * MemberPurchaseReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ashlyhernandez
 */

#include "MemberPurchaseReport.h"

MemberPurchaseReport::MemberPurchaseReport()
{
	memberSales.clear();
}

MemberPurchaseReport::MemberPurchaseReport(list<RegularMember>   regularIn,
				     	 	 	 	 	   list<ExecutiveMember> executiveIn,
				     	 	 	 	 	   list<Sale> 		     salesIn,
				     	 	 	 	 	   string 				 memberName)
{
	list<RegularMember>::iterator   regular   = regularIn.begin();
	list<ExecutiveMember>::iterator executive = executiveIn.begin();
	list<Sale>::iterator 			sales     = salesIn.begin();
	int nameToId;

	while(regular != regularIn.end() || executive != executiveIn.end())
	{
		if(regular->GetMember() == memberName)
		{
			nameToId = regular->GetNumber();

			while(sales != salesIn.end())
			{
				if(nameToId == sales->GetMemberID())
				{
					memberSales.push_back(*sales);
				}//END - (nameToId == sales->GetMemberID())
				sales++;
			}//END - while(sales != salesIn.end())
		}//END - if(check regular Member)


		if(executive->GetMember() == memberName)
		{
			nameToId = executive->GetNumber();

			while(sales != salesIn.end())
			{
				if(nameToId == sales->GetMemberID())
				{
					memberSales.push_back(*sales);
				}//END - if(nameToId == sales->GetMemberID())
				sales++;
			}//END - while(sales != salesIn.end())
		}//END

		regular++;
		executive++;
	}

}


MemberPurchaseReport::MemberPurchaseReport(list<Sale> salesIn,
										   int	      idIn)
{
	list<Sale>::iterator sales = salesIn.begin();

	while(sales != salesIn.end())
	{
		if(sales->GetMemberID() == idIn)
		{
			memberSales.push_back(*sales);
		}
		sales++;
	}
}


MemberPurchaseReport::~MemberPurchaseReport()
{
	memberSales.clear();
}



list<Sale> MemberPurchaseReport::GetSales() const
{
	return memberSales;
}








