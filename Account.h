#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
private:
	string m_accountNumber;
	double m_accountBalance;

public:
	Account();
	Account(string accountNumber, double accountBalance);
	
	string GetAccountNumber();
	double GetAccountBalance();
	void SetAccountNumber(string accountNumber);
	void SetAccountBalance(double accountBalance);

	virtual string toString() = 0;
	virtual void deposit(double depositAmount) = 0;
	virtual void withdrawal(double withdrawalAmount) = 0;
};

#endif // !ACCOUNT_H