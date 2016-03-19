/*
 * RebatesReport.h
 *
 *  Created on: Mar 7, 2016
 *      Author: ahernandez109
 */

#ifndef REBATESREPORT_H_
#define REBATESREPORT_H_

#include "Member.h"
#include <list>

/*A report that prints out the rebate of all the Executive members sorted by 
 * membership number.
 */
class RebatesReport
{
public:
    RebatesReport(list<Member>* membersIn);

    ~RebatesReport();

    const list<Member>& GetExecutiveMembers() const;

private:
    list<Member>* rebates;
};

#endif /* REBATESREPORT_H_ */
