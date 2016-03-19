#include "Items.h"

Item::Item()
{
	itemName = " ";

	price = 0.00;
}


Item::Item(QString name, double money)
{
	itemName = name;
	price    = money;
}


void Item::SetItem(QString name)
{
	itemName = name;
}

void Item::SetPrice(double money)
{
	price = money;
}

QString Item::GetItem() const
{
	return itemName;
}

double Item::GetPrice() const
{
	return price;
}
