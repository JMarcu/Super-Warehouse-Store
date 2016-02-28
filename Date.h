/*
 * Date.h
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
using namespace std;

class Date {
	public:

		Date();
		Date(int monthIn, int dayIn, int yeaerIn);

		virtual ~Date();

		void UpdateDate(int newMonth, int newDay, int newYear);
		void PrintDate() const;
		int GetMonth() const;
		int GetDay() const;
		int Getyear() const;



	private:
		int month;
		int day;
		int year;
};

#endif /* DATE_H_ */
