/*
 * RebatesReport.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#include "RebatesReport.h"

/**
 * @brief RebatesReport::RebatesReport
 * @param membersIn
 */
RebatesReport::RebatesReport(std::list<Member>* membersIn){
    rebates = membersIn;
}

/**
 * @brief RebatesReport::~RebatesReport
 */
RebatesReport::~RebatesReport(){
    rebates->clear();
    delete rebates;
}

/**
 * @brief RebatesReport::GetExecutiveMembers
 * @return
 */
const std::list<Member>& RebatesReport::GetExecutiveMembers() const{
    return *rebates;
}
