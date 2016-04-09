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
    /**
     * @brief DailySalesReport
     * @param salesListIn - list of sales made onday
     * @param mems - list of members bought on date
     *  - initialzes an instance of DailySalesReport
     */
    DailySalesReport (std::list<Sale>*   salesListIn,
                      std::list<Member>* mems);


    ~DailySalesReport();

    /**
     * @brief GetDailySales
     * @return - list of sales made that day
     */
    const std::list<Sale>& GetDailySales() const;

    /**
     * @brief GetAllMembers
     * @return - list of members that purchases on Date
     */
    const std::list<Member>& GetAllMembers() const;

    /**
     * @brief GetRegularCount
     * @return - Number of Regular members who bought on Date
     */
    int GetRegularCount() const;

    /**
     * @brief GetExecutiveCount
     * @return - number of Executive members bought on Date
     */
    int GetExecutiveCount() const;

private:
    std::list<Sale>* salesList;//List of all relevant sales on the given day.
    std::list<Member>* members;//List of all relevant members who mad purchases.
    int regCount; //Count of all relevant members with regular accounts.
    int execCount;//Count of all relevant members with executive accounts.


};

#endif /* DAILYSALESREPORT_H_ */
