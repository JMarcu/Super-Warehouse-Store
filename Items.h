#ifndef ITEMS_H_
#define ITEMS_H_

#include <iostream>
#include <QString>
using namespace std;

class Item
{
	public:
	
    /**
     * @brief Item
     */
	Item();
    /**
     * @brief Item
     * @param name
     */
    Item(QString name);
    /**
     * @brief Item
     * @param name
     * @param money
     */
	Item(QString name, double money);

    /**
     * @brief SetItem
     * @param name
     */
	void SetItem(QString name);

    /**
     * @brief SetPrice
     * @param money
     */
	void SetPrice(double money);
	
    /**
     * @brief GetItem
     * @return
     */
	QString GetItem() const;

    /**
     * @brief GetPrice
     * @return
     */
	double GetPrice() const; 

	
private:
    /**
     * @brief itemName
     */
    QString itemName;
    /**
     * @brief price
     */
    double price;
};

#endif
