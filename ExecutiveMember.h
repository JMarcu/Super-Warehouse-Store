/*
 * ExecutiveMember.h
 *
 *  Created on: Feb 24, 2016
 *      Author: ashlyhernandez
 */

#ifndef EXECUTIVEMEMBER_H_
#define EXECUTIVEMEMBER_H_

#include <RegularMember.h>

class ExecutiveMember : public RegularMember
{
public:
	ExecutiveMember();
	ExecutiveMember(string newName,
			  int 	 newNumber,
			  Date   newDate,
			  double newTotal,
			  int newRebate);
	virtual ~ExecutiveMember();

	int GetRebate() const;
	void SetRebate(int newRebate);



	int rebate;
};

#endif /* EXECUTIVEMEMBER_H_ */
