#include "ExecutiveConversionReport.h"

ExecutiveConversionReport::ExecutiveConversionReport(list<Member>* allExecMembers){
    membersToConvert = new list<Member>;
    
    list<Member>::iterator it = allExecMembers->begin();
    
    while(it != allExecMembers->end()){
        if(it->ShouldConvertMembership()){
            membersToConvert->push_back(*it);
        }
        
        it++;
    }
    
    allExecMembers->clear();
    delete allExecMembers;
}

ExecutiveConversionReport::~ExecutiveConversionReport(){
    membersToConvert->clear();
    delete membersToConvert;
}

const list<Member>& ExecutiveConversionReport::GetMembersToConvert() const{
    return *membersToConvert;
}