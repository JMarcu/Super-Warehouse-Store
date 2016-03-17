#include "ExecutiveConversionReport.h"

ExecutiveConversionReport::ExecutiveConversionReport(list<Member>* allExecMembers){
    list<Member>::iterator it = allExecMembers->begin();
    
    while(it != allExecMembers->end()){
        if(it->ShouldConvertMembership()){
            membersToConvert.push_back(*it);
        }
        
        it++;
    }
}

ExecutiveConversionReport::~ExecutiveConversionReport(){
    membersToConvert.clear();
}

const list<Member>& ExecutiveConversionReport::GetMembersToConvert() const{
    return membersToConvert;
}