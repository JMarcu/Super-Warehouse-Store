#ifndef ITEMS_H_
#define ITEMS_H_

#include <iostream>
#include <QString>
using namespace std;

class Item
{
	public:
	
	// Constructors/Destructors
	Item();
	Item(QString name, double money);

//   Methods(Mutators)
//   -----------------
	void SetItem(QString name);

	void SetPrice(double money);
	

//  Accessors
// --------------
	QString GetItem() const;

	double GetPrice() const; 

	
private:
//  Data members(variables)
// -------------------------
    QString itemName;
    double price;
};

#endif
