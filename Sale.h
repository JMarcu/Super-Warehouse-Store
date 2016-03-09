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

#include <string>
#include "Date.h"
using namespace std;

class Sale
{
    int    memberID;
    string itemName;
    int    quantityPurchased;
    float  totalCost;
    Date   orderDate;

public:

	//constructors
	Sale(); //default constructor

	Sale(int id, string n, int q, float c, Date d);

	//Methods
        int    GetMemberID() const;
        
	string GetItemName() const;
        
        int    GetQuantityPurchased() const;

	float  GetTotalCost() const;
        
        Date   GetOrderDate() const;
        

};//end Sales class



#endif /* SALE_H_ */
