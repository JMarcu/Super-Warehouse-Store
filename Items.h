#ifndef ITEMS_H_
#define ITEMS_H_

#include <iostream>
#include <string>
using namespace std;

class Item
{
	public:
	
	// Constructors/Destructors
	Item();
	Item(string name, int amounts, double money);
	~Item();

//   Methods(Mutators)
//   -----------------
	void SetItem(string name);

	void SetItemProfile(string name, int amountz, double money);

	void SetAmount(int amountz);

	void SetPrice(double money);
	
	Item *AddNode(Item *head, Item *perPtr);
	

	

//  Accessors
// --------------
	string GetItem();

	int GetAmount();

	double GetPrice(); 
	
	Item *GoNext(Item *ptr);

	
private:
//  Data members(variables)
// -------------------------
    string itemName;
    int quantity;
    double price;
    Item *next;
};

#endif
