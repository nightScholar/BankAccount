#include "Savings.h"
#include "ErrorClass.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Savings::Savings()
{

}

Savings::Savings(double interestRate, double accumulatedInterestPaid, string acccountNumber, double accountBalance) : Account(acccountNumber, accountBalance)
{
	m_interestRate = interestRate;
	m_accumulatedInterestPaid = accumulatedInterestPaid;
}

string Savings::toString()
{
	stringstream ss("");
	ss << "Account Number: " << GetAccountNumber() << endl;
	ss << "Balance: $" << fixed << setprecision(2) << GetAccountBalance() << endl;
	ss << "Interest Rate: " << fixed << setprecision(4) << GetInterestRate() << endl;
	ss << "Interest Paid: $" << fixed << setprecision(2) << calculateInterestRate() << endl;
	return ss.str();
}

double Savings::GetInterestRate()
{
	return m_interestRate;
}

double Savings::GetAccumulatedInterestPaid()
{
	return m_accumulatedInterestPaid;
}

void Savings::SetInterestRate(double interestRate)
{	
	if (interestRate < MINIMUM_INTEREST_RATE || interestRate > MAXIMUM_INTEREST_RATE)
	{
		throw InterestRate();
	}
	else
	{
		m_interestRate = interestRate;
	}
}

void Savings::SetAccmulatedInterestPaid(double interestPaid)
{
	m_accumulatedInterestPaid = interestPaid;
}

void Savings::deposit(double depositAmount)
{
	double balance = GetAccountBalance() + depositAmount;
	SetAccountBalance(balance);
}

void Savings::withdrawal(double withdrawalAmount)
{
	double balance = GetAccountBalance();
	
	if (withdrawalAmount > balance)
	{
		throw Withdrawal();
	}
	else
	{
		balance = GetAccountBalance() - withdrawalAmount;
		SetAccountBalance(balance);
	}
}

double Savings::calculateInterestRate()
{
	double interest = m_accumulatedInterestPaid + GetAccountBalance() * m_interestRate;
	return interest;
}

double Savings::MINIMUM_INTEREST_RATE = 0.03;
double Savings::MAXIMUM_INTEREST_RATE = 0.065;