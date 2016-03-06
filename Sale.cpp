/*************************************************************************
 * AUTHOR         : Derek Miller
 * STUDENT ID     : 337408
 * GROUP PROJECT  : Sales
 * CLASS          : CS1C
 * SECTION        : MW - 2:00pm
 * DUE DATE       :
 *************************************************************************/

#include "Sale.h"

//constructors
Sale::Sale() //default constructor
{
    memberID = 0;
    itemName = "";
    quantityPurchased = 0;
    totalCost = 0.0;
    orderDate = new Date();
}

Sale::Sale (int id, string n, int q, float c, Date d)
{
    memberID = id;
    itemName = n;
    quantityPurchased = q;
    totalCost = c;
    orderDate = d;
}

//Methods
int Sale::GetMemberID(){
    return memberID;
}

string Sale::GetItemName()
{
    return itemName;
}

int Sale::GetQuantityPurchased()
{
    return quantityPurchased;
}

float Sale::GetTotalCost ()
{
    return totalCost;
}

Date Sale::GetOrderDate(){
    return orderDate;
}


