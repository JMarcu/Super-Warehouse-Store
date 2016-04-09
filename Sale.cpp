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

/**
 * @brief Sale::Sale
 */
Sale::Sale() //default constructor
{
    memberID = 0;
    itemName = "";
    quantityPurchased = 0;
    subtotal = 0.0;
    orderDate = *(new Date());
}

/**
 * @brief Sale::Sale
 * @param id
 * @param n
 * @param q
 * @param c
 * @param d
 */
Sale::Sale (int id, QString n, int q, float c, Date d)
{
    memberID = id;
    itemName = n;
    quantityPurchased = q;
    subtotal = c;
    orderDate = d;
}

/**
 * @brief Sale::GetMemberID
 * @return
 */
int Sale::GetMemberID() const{
    return memberID;
}

/**
 * @brief Sale::GetItemName
 * @return
 */
QString Sale::GetItemName() const
{
    return itemName;
}

/**
 * @brief Sale::GetQuantityPurchased
 * @return
 */
int Sale::GetQuantityPurchased() const
{
    return quantityPurchased;
}

/**
 * @brief Sale::GetSubtotal
 * @return
 */
float Sale::GetSubtotal () const
{
    return subtotal;
}

/**
 * @brief Sale::GetOrderDate
 * @return
 */
Date Sale::GetOrderDate() const{
    return orderDate;
}


