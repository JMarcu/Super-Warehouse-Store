/*************************************************************************
 * AUTHOR         : Derek Miller
 * STUDENT ID     : 337408
 * GROUP PROJECT  : Sales
 * CLASS          : CS1C
 * SECTION        : MW - 2:00pm
 * DUE DATE       :
 *************************************************************************/

#ifndef SALE_H_
#define SALE_H_

#include <QString>
#include "date.h"
using namespace std;

class Sale
{
    int    memberID;
    QString itemName;
    int    quantityPurchased;
    float  subtotal;
    Date   orderDate;

public:

    /**
     * @brief Sale
     */
    Sale();

    /**
     * @brief Sale
     * @param id
     * @param n
     * @param q
     * @param c
     * @param d
     */
	Sale(int id, QString n, int q, float c, Date d);

    /**
     * @brief GetMemberID
     * @return
     */
    int    GetMemberID() const;

    /**
     * @brief GetItemName
     * @return
     */
	QString GetItemName() const;

    /**
     * @brief GetQuantityPurchased
     * @return
     */
    int    GetQuantityPurchased() const;

    /**
     * @brief GetSubtotal
     * @return
     */
	float  GetSubtotal() const;

    /**
     * @brief GetOrderDate
     * @return
     */
    Date   GetOrderDate() const;
        

};//end Sales class



#endif /* SALE_H_ */
