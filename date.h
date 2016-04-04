#ifndef DATE_H
#define DATE_H

#include <QString>


class Date
{
public:

    /**
     * @brief Date
     */
    Date();

    /**
     * @brief Date
     * @param monthIn
     * @param dayIn
     * @param yearIn
     */
    Date(int monthIn, int dayIn, int yearIn);
            Date(QString dateString);

    virtual ~Date();

            /**
     * @brief UpdateDate
     * @param newMonth
     * @param newDay
     * @param newYear
     */
    void UpdateDate(int newMonth,
                    int newDay,
                    int newYear);
    /**
     * @brief PrintDate
     */
    void PrintDate() const;
    /**
     * @brief GetMonth
     * @return
     */
    int GetMonth() const;
    /**
     * @brief GetDay
     * @return
     */
    int GetDay() const;
    /**
     * @brief GetYear
     * @return
     */
    int GetYear() const;

    /**
     * @brief toString
     * @return
     */
    QString toString() const;

private:
    int month;
    int day;
    int year;
};

#endif // DATE_H


