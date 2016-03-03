/*************************************************************************
 * AUTHOR         : Derek Miller
 * STUDENT ID     : 337408
 * GROUP PROJECT  : Sales
 * CLASS          : CS1C
 * SECTION        : MW - 2:00pm
 * DUE DATE       :
 *************************************************************************/

#ifndef SALES_H_
#define SALES_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
using namespace std;

class Sales
{

	string item;
	float itemCost;
	int totalItems;
	float totalCost;

public:

	//constructors
	Sales(); //default constructor

	Sales (string itemF, float itemCostF);

	Sales (string itemF, float itemCostF, int totalItemsF, float totalCostF);

	//d-constructor
	~Sales();

	//Methods
	void ChangeItem(string itemF);

	void ChangeCost(float itemCostF);

	void ChangeAll(string itemF, float itemCostF, int totalItemsF,
			float totalCostF);

	int GetTotalItems(int totalItemsF);

	float GetTotalCost (int totalItemsF, float itemCostF);
	

//	void Print() const;       *Don't quite need when using GUI*

};//end Sales class



#endif /* SALES_H_ */
