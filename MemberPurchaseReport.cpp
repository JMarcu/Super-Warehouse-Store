#include "MemberPurchaseReport.h"

MemberPurchaseReport::MemberPurchaseReport(const Member*     mem,
                                           const list<Sale>* saleList)
{
    member = mem;
    sales  = saleList;
}

MemberPurchaseReport::~MemberPurchaseReport()
{
    delete sales;
    delete member;
}

const list<Sale>& MemberPurchaseReport::GetSales() const{
    return *sales;
}

const Member& MemberPurchaseReport::GetMember() const{
    return *member;
}