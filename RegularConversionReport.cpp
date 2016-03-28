#include "RegularConversionReport.h"

RegularConversionReport::RegularConversionReport(std::list<Member>* allRegularMembers){
    std::list<Member>::iterator it = allRegularMembers->begin();
    
    while(it != allRegularMembers->end()){
        if(it->ShouldConvertMembership()){
            membersToConvert.push_back(*it);
        }
        
        it++;
    }
    
    allRegularMembers->clear();
    delete allRegularMembers;
}

RegularConversionReport::~RegularConversionReport(){
    membersToConvert.clear();
}

const std::list<Member>& RegularConversionReport::GetMembersToConvert() const{
    return membersToConvert;
}
