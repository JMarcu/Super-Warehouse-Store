/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegularConversionReport.h
 * Author: james
 *
 * Created on March 16, 2016, 4:46 PM
 */

#ifndef REGULARCONVERSIONREPORT_H
#define REGULARCONVERSIONREPORT_H

#include "Member.h"
#include <list>

/*Your program should be able to determine if any Regular
  customer should convert their membership to Executive status.*/

class RegularConversionReport{
private:
    list<Member> membersToConvert;
    
public:
    RegularConversionReport(list<Member>* allRegularMembers);
    ~RegularConversionReport();
    
    const list<Member>& GetMembersToConvert() const;
};


#endif /* REGULARCONVERSIONREPORT_H */

