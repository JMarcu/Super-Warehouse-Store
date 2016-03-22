#include "MemberPurchaseReport.h"

MemberPurchaseReport::MemberPurchaseReport(Member*     mem,
                                           std::list<Sale>* saleList)
{
    member = mem;
    sales  = saleList;
}

MemberPurchaseReport::~MemberPurchaseReport()
{
    sales->clear();
    
    delete sales;
    delete member;
}

const std::list<Sale>& MemberPurchaseReport::GetSales() const{
    return *sales;
}

const Member& MemberPurchaseReport::GetMember() const{
    return *member;
}
