/*
 * RebatesReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "RebatesReport.h"

RebatesReport::RebatesReport(std::list<Member>* membersIn){
    rebates = membersIn;
}

RebatesReport::~RebatesReport(){
    rebates->clear();
    delete rebates;
}

const std::list<Member>& RebatesReport::GetExecutiveMembers() const{
    return *rebates;
}
