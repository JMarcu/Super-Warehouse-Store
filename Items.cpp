#include "Items.h"

Item::Item()
{
	itemName = " ";

	quantity = 0;

	price = 0.00;
	
	next = NULL;
}


Item::Item(string name, int amountz, double money)
{
	itemName = name;
	quantity = amountz;
	price = money;
	
	next = NULL;
}

Item::~Item()
{

}

void Item::SetItem(string name)
{
	itemName = name;
}
void Item::SetItemProfile(string name, int amountz, double money)
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

Item *AddNode(Item *head, Item *perPtr)
{
	perPtr -> next = head;
	head = perPtr;
	
	return head;
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

Item *GoNext(Item *ptr)
{
	ptr = ptr -> next;
	return ptr;	
}
