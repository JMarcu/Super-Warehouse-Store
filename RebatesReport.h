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
