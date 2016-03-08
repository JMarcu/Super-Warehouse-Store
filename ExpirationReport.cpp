/*
 * ExpirationReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "ExpirationReport.h"

ExpirationReport::ExpirationReport()
{
	expiredAccounts.clear();
}

ExpirationReport::~ExpirationReport()
{
	expiredAccounts.clear();
}

ExpirationReport::ExpirationReport(list<ExecutiveMember> membersIn,
								   Date 				 expirationDate)
{
	list<ExecutiveMember>::iterator executive = membersIn.begin();

	while(executive != membersIn.end())
	{
		if(executive->GetExpiration().GetMonth() == expirationDate.GetMonth())
		{
			expiredAccounts.push_back(*executive);
		}

		executive++;

	}//END - (executive != membersIn.end())
}

list<ExecutiveMember> ExpirationReport::GetExpiredAccounts() const
{
	return expiredAccounts;
}
