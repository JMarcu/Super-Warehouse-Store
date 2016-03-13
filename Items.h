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
	Item(QString name, int amounts, double money);
	~Item();

//   Methods(Mutators)
//   -----------------
	void SetItem(QString name);

	void SetItemProfile(QString name, int amountz, double money);

	void SetAmount(int amountz);

	void SetPrice(double money);
	

//  Accessors
// --------------
	QString GetItem() const;

	int GetAmount() const;

	double GetPrice() const; 

	
private:
//  Data members(variables)
// -------------------------
    QString itemName;
    int quantity;
    double price;
};

#endif
