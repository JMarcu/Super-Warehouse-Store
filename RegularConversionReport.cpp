#include "RegularConversionReport.h"

/**
 * @brief RegularConversionReport::RegularConversionReport
 * @param allRegularMembers
 */
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

/**
 * @brief RegularConversionReport::~RegularConversionReport
 */
RegularConversionReport::~RegularConversionReport(){
    membersToConvert.clear();
}

/**
 * @brief RegularConversionReport::GetMembersToConvert
 * @return
 */
const std::list<Member>& RegularConversionReport::GetMembersToConvert() const{
    return membersToConvert;
}
