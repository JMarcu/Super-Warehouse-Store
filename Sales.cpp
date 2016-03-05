/*************************************************************************
 * AUTHOR         : Derek Miller
 * STUDENT ID     : 337408
 * GROUP PROJECT  : Sales
 * CLASS          : CS1C
 * SECTION        : MW - 2:00pm
 * DUE DATE       :
 *************************************************************************/


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
	Sales *next;

public:

	//constructors
	Sales() //default constructor
	{
		item = "X";
		itemCost = 0.0;
		totalItems = 0;
		totalCost = 0.0;
		next = NULL;
	}

	Sales (string itemF, float itemCostF)
	{
		item = itemF;
		itemCost = itemCostF;
	}

	Sales (string itemF, float ItemCostF, int totalItemsF)
	{
		item = itemF;
		itemCost = ItemCostF;
		totalItems = totalItemsF;
		totalCost = itemCost * totalItems;
		next = NULL;
	}


	//d-constructor
	//~Sales();

	//Methods
	void ChangeItem(string itemF)
	{
		item = itemF;
	}

	void ChangeCost(float itemCostF)
	{
		itemCost = itemCostF;
	}

	void ChangeAll(string itemF, float itemCostF, int totalItemsF,
			float totalCostF)
	{
		item = itemF;
		itemCost = itemCostF;
		totalItems = totalItemsF;
		totalCost = totalCostF;
	}

	string GetItemName()
	{
		return item;
	}

	int GetTotalItems(int totalItemsF)
	{
		return totalItemsF;
	}

	float GetItemCost()
	{
		return itemCost;
	}
	
	float GetTotalCost (int totalItemsF, float itemCostF)
	{
		totalCost+= itemCostF;
		return totalCost;

	}

	void Print() const
	{
		cout << "Item: " << item << endl << "Item Cost: " << itemCost
				<< endl << "Total Items: " <<  totalItems << endl
				<< "Total Cost: " << totalCost << endl << endl;
	}
	
	Sales *AddObject(Sales *head, Sales *ptr)
	{
		ptr -> next = head;
		head = ptr;
		
		return head;
	}
	
	Sales *PointNext(Sales *ptr)
	{
		ptr = ptr -> next;
		
		return ptr;
	}

};//end Employees class

