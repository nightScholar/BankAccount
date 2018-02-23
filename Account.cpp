#include "Account.h"
using namespace std;

Account::Account()
{

}

Account::Account(string accountNumber, double accountBalance)
{
	m_accountNumber = accountNumber;
	m_accountBalance = accountBalance;
}

string Account::GetAccountNumber()
{
	return m_accountNumber;
}

double Account::GetAccountBalance()
{
	return m_accountBalance;
}

void Account::SetAccountNumber(string accountNumber)
{
	m_accountNumber = accountNumber;
}

void Account::SetAccountBalance(double accountBalance)
{
	m_accountBalance = accountBalance;
}