#include "MemberPurchaseReport.h"


/**
 * @brief MemberPurchaseReport::MemberPurchaseReport
 * @param mem
 * @param saleList
 */
MemberPurchaseReport::MemberPurchaseReport(Member*     mem,
                                           std::list<Sale>* saleList)
{
    member = mem;
    sales  = saleList;
}

/**
 * @brief MemberPurchaseReport::~MemberPurchaseReport
 */
MemberPurchaseReport::~MemberPurchaseReport()
{
    sales->clear();
    
    delete sales;
    delete member;
}

/**
 * @brief MemberPurchaseReport::GetSales
 * @return
 */
const std::list<Sale>& MemberPurchaseReport::GetSales() const{
    return *sales;
}

/**
 * @brief MemberPurchaseReport::GetMember
 * @return
 */
const Member& MemberPurchaseReport::GetMember() const{
    return *member;
}
