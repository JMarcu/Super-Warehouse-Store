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
#include "Date.h"
using namespace std;

class Sale
{
    int    memberID;
    QString itemName;
    int    quantityPurchased;
    float  subtotal;
    Date   orderDate;

public:

	//constructors
	Sale(); //default constructor

	Sale(int id, QString n, int q, float c, Date d);

	//Methods
        int    GetMemberID() const;
        
	QString GetItemName() const;
        
        int    GetQuantityPurchased() const;

	float  GetSubtotal() const;
        
        Date   GetOrderDate() const;
        

};//end Sales class



#endif /* SALE_H_ */
