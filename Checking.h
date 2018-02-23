#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include <string>
using namespace std;

class Checking : public Account
{
private:
	bool m_overdraftProtection;
	double m_loans;

public:
	Checking();
	Checking(bool overdraftProtection, double loans, string accountNumber, double accountBalance);

	string toString();
	bool GetOverdraftProtection();
	double GetLoans();
	void SetOverdraftProtection(bool overdraftProtection);
	void SetLoans(double loanAmount);

	void deposit(double depositAmount);
	void withdrawal(double withdrawalAmount);

};

#endif // !CHECKING_H