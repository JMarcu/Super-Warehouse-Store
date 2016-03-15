/*************************************************************************
 * AUTHOR         : Derek Miller
 * STUDENT ID     : 337408
 * GROUP PROJECT  : Sales
 * CLASS          : CS1C
 * SECTION        : MW - 2:00pm
 * DUE DATE       :
 *************************************************************************/

#include "Sale.h"
using namespace std;

//constructors
Sale::Sale() //default constructor
{
    memberID = 0;
    itemName = "";
    quantityPurchased = 0;
    subtotal = 0.0;
    orderDate = *(new Date());
}

Sale::Sale (int id, QString n, int q, float c, Date d)
{
    memberID = id;
    itemName = n;
    quantityPurchased = q;
    subtotal = c;
    orderDate = d;
}

//Methods
int Sale::GetMemberID() const{
    return memberID;
}

QString Sale::GetItemName() const
{
    return itemName;
}

int Sale::GetQuantityPurchased() const
{
    return quantityPurchased;
}

float Sale::GetSubtotal () const
{
    return subtotal;
}

Date Sale::GetOrderDate() const{
    return orderDate;
}


