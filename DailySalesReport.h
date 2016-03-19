/*
 * DailySalesReport.h
 *
 *  Created on: Mar 6, 2016
 *      Author: ashlyhernandez
 */

#ifndef DAILYSALESREPORT_H
#define DAILYSALESREPORT_H

#include "Sale.h"
#include "Items.h"
#include "Member.h"
#include <list>

/* A sales report for any given day. It should include a list of items
 * and quantities sold on that day as well names of the members
 * who shopped that day. Report the total revenue for the given
 * day. It should also include number of Executive members and
 * Regular members who shopped during the given day. Provide an
 * option to generate the report by membership type.
 */
class DailySalesReport {
public:
    //Constructor and Destructor
    DailySalesReport (list<Sale>*   salesListIn,
                      list<Member>* mems);
    ~DailySalesReport();

    //Getters
    const list<Sale>& GetDailySales() const;
    const list<Member>& GetAllMembers() const;
    int GetRegularCount() const;
    int GetExecutiveCount() const;

private:
    list<Sale>* salesList;//List of all relevant sales on the given day.
    list<Member>* members;//List of all relevant members who mad purchases.
    int regCount; //Count of all relevant members with regular accounts.
    int execCount;//Count of all relevant members with executive accounts.


};

#endif /* DAILYSALESREPORT_H_ */
