#include "RegularConversionReport.h"

RegularConversionReport::RegularConversionReport(list<Member>* allRegularMembers){
    list<Member>::iterator it = allRegularMembers->begin();
    
    while(it != allRegularMembers->end()){
        if(it->ShouldConvertMembership()){
            membersToConvert.push_back(*it);
        }
        
        it++;
    }
}

RegularConversionReport::~RegularConversionReport(){
    membersToConvert.clear();
}

const list<Member>& RegularConversionReport::GetMembersToConvert() const{
    return membersToConvert;
}