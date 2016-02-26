#include "Items.h"

Items::Item()
{
	itemName = " ";

	quantity = 0;

	price = 0.00;
}


Items::Item(string name, int amountz, double money)
{
	itemName = name;
	quantity = amountz;
	price = money;
}

Items::~Item()
{

}

void Item::SetItem(string name)
{
	itemName = name;
}
void SetItemProfile(string name, int amountz, double money)
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

void Item::SetItemAll(string name, int amountz, double money)
{
	itemName = name;
	quantity = amountz;
	price = money;
}



string Item::GetItem()
{
	return itemName;
}

int Item::GetAmount()
{
	return quantity;
}

double Item::GetPrice()
{
	return price;
}
