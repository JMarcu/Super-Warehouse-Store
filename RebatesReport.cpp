/*
 * RebatesReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "RebatesReport.h"

RebatesReport::RebatesReport()
{
	rebates.clear();
}

RebatesReport::RebatesReport(list<ExecutiveMember> membersIn)
{
	list<ExecutiveMember>::iterator executive = membersIn.begin();

	while(executive != membersIn.end())
	{
		rebates.push_back(*executive);
		executive++;
	}
}

RebatesReport::~RebatesReport()
{
	rebates.clear();
}

list<ExecutiveMember> RebatesReport::GetRebatesReport() const
{
	return rebates;
}
