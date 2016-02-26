#ifndef ITEMS_H_
#define ITEMS_H_


#include <iostream>
#include <string>

class Item
{
	public:
	
	// Constructors/Destructors
	Items();
	Items(string name, int amountz, double money);
	~Items();

//   Methods(Mutators)
//   -----------------
	void SetItem(string name);

	void SetItemProfile(string name, int amountz, double money);

	void SetAmount(int amountz);

	void SetPrice(double money);

	

//  Accessors
// --------------
	string GetItem();

	int GetAmount();

	double GetPrice(); 

	
	private:
	
//  Data members(variables)
// -------------------------

	string itemName;

	int quantity;

	double price;	
}

#endif
