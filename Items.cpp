#include "Items.h"

Item::Item()
{
	itemName = " ";

	quantity = 0;

	price = 0.00;
}


Item::Item(QString name, int amountz, double money)
{
	itemName = name;
	quantity = amountz;
	price = money;
}

Item::~Item()
{

}

void Item::SetItem(QString name)
{
	itemName = name;
}
void Item::SetItemProfile(QString name, int amountz, double money)
{
	itemName = name;
	quantity = amountz;
	price = money;
}

void Item::SetAmount(int amountz)
{
	quantity = amountz;
}


void Item::SetPrice(double money)
{
	price = money;
}

string Item::GetItem() const
{
	return itemName;
}

int Item::GetAmount() const
{
	return quantity;
}

double Item::GetPrice() const
{
	return price;
}
