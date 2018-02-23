#include "Checking.h"
#include "ErrorClass.h"
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

Checking::Checking()
{
	
}

Checking::Checking(bool overdraftProtection, double loans, string accountNumber, double accountBalance) : Account(accountNumber, accountBalance)
{
	m_overdraftProtection = overdraftProtection;
	m_loans = loans;
}

string Checking::toString()
{
	stringstream ss("");
	ss << "Account Number: " << GetAccountNumber() << endl;
	ss << "Balance: $" << fixed << setprecision(2) << GetAccountBalance() << endl;
	ss << "Overdraft Protection: ";
		if (GetOverdraftProtection() == 1)
		{
			ss << "True" << endl;
		}
		else if (GetOverdraftProtection() == 0)
		{
			ss << "False" << endl;
		}
	ss << "Loan Amount: $" << fixed << setprecision(2) << GetLoans() << endl;
	return ss.str();
}

bool Checking::GetOverdraftProtection()
{
	return m_overdraftProtection;
}

double Checking::GetLoans()
{
	return m_loans;
}

void Checking::SetOverdraftProtection(bool overdraftProtection)
{
	m_overdraftProtection = overdraftProtection;
}

void Checking::SetLoans(double loanAmount)
{
	m_loans = loanAmount;
}

void Checking::deposit(double depositAmount)
{
	double tempLoan = 0;
	double balance = GetAccountBalance();

	if (m_loans > 0.0)
	{
		tempLoan = m_loans - depositAmount;
		SetLoans(tempLoan);
		
		if (tempLoan < 0)
		{
			SetAccountBalance(abs(tempLoan));
			SetLoans(0);
		}
	}
	else
	{
		balance = GetAccountBalance() + depositAmount;
		SetAccountBalance(balance);
	}
}

void Checking::withdrawal(double withdrawalAmount)
{
	double balance = GetAccountBalance();
	double temploan = 0;

	if (m_overdraftProtection == false && balance < withdrawalAmount)
	{
		throw Overdraft();
	}

	else if (m_overdraftProtection == true && balance < withdrawalAmount)
	{
		temploan = withdrawalAmount - balance;
		SetLoans(temploan);
		SetAccountBalance(0);
	}
	else
	{
		balance = GetAccountBalance() - withdrawalAmount;
		SetAccountBalance(balance);
	}
}