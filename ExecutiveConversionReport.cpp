#include "ExecutiveConversionReport.h"

ExecutiveConversionReport::ExecutiveConversionReport(std::list<Member>* allExecMembers){
    membersToConvert = new std::list<Member>;
    
    std::list<Member>::iterator it = allExecMembers->begin();
    
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

const std::list<Member>& ExecutiveConversionReport::GetMembersToConvert() const{
    return *membersToConvert;
}
