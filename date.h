#ifndef DATE_H
#define DATE_H

#include <QString>


class Date
{
public:

        Date();
        Date(int monthIn, int dayIn, int yearIn);
                Date(QString dateString);

        virtual ~Date();

        void UpdateDate(int newMonth,
                        int newDay,
                        int newYear);
        void PrintDate() const;
        int GetMonth() const;
        int GetDay() const;
        int GetYear() const;

         QString toString() const;

    private:
        int month;
        int day;
        int year;
};

#endif // DATE_H


