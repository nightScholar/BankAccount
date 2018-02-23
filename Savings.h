#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"
#include <string>
using namespace std;

class Savings : public Account
{
private:
	double m_interestRate;
	double m_accumulatedInterestPaid;

public:
	Savings();
	Savings(double interestRate, double accumulatedInterestPaid, string accountNumber, double accountBalance);

	double GetInterestRate();
	double GetAccumulatedInterestPaid();
	void SetInterestRate(double interestRate);
	void SetAccmulatedInterestPaid(double interestPaid);

	string toString();
	void deposit(double depositAmount);
	void withdrawal(double withdrawalAmount);
	double calculateInterestRate();

	static double MINIMUM_INTEREST_RATE;
	static double MAXIMUM_INTEREST_RATE;
};

#endif // !SAVINGS_H