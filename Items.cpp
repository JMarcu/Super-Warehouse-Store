#include "Items.h"
#include <QDebug>

/**
 * @brief Item::Item
 */
Item::Item()
{
	itemName = " ";

    price = 0.00;
}

/**
 * @brief Item::Item
 * @param name
 */
Item::Item(QString name)
{
    itemName = name;
}


/**
 * @brief Item::Item
 * @param name
 * @param money
 */
Item::Item(QString name, double money)
{
	itemName = name;
	price    = money;
}


/**
 * @brief Item::SetItem
 * @param name
 */
void Item::SetItem(QString name)
{
	itemName = name;
}

/**
 * @brief Item::SetPrice
 * @param money
 */
void Item::SetPrice(double money)
{
	price = money;
}

/**
 * @brief Item::GetItem
 * @return
 */
QString Item::GetItem() const
{
	return itemName;
}

/**
 * @brief Item::GetPrice
 * @return
 */
double Item::GetPrice() const
{
	return price;
}
