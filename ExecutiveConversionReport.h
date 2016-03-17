/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExecutiveConversionReport.h
 * Author: james
 *
 * Created on March 16, 2016, 4:55 PM
 */

#ifndef EXECUTIVECONVERSIONREPORT_H
#define EXECUTIVECONVERSIONREPORT_H

#include "Member.h"
#include <list>

class ExecutiveConversionReport{
private:
    list<Member> membersToConvert;
    
public:
    ExecutiveConversionReport(list<Member>* allExecMembers);
    ~ExecutiveConversionReport();
    
    const list<Member>& GetMembersToConvert() const;
};

#endif /* EXECUTIVECONVERSIONREPORT_H */

