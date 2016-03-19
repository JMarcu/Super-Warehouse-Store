#include "MemberPurchaseReport.h"

MemberPurchaseReport::MemberPurchaseReport(Member*     mem,
                                           list<Sale>* saleList)
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

const list<Sale>& MemberPurchaseReport::GetSales() const{
    return *sales;
}

const Member& MemberPurchaseReport::GetMember() const{
    return *member;
}