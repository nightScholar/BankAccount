// BankAccounts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Generating a Savings Account object and placing it into the vector:" << endl << endl;
	Savings saving(0.0641, 0.00, "A5792S", 0);
	Account* pSavingsAccount = &saving;

	cout << "Generating a Checking Account object and placing it into the same vector:" << endl << endl;
	Checking checking(false, 0, "A1186C", 0);
	Account* pCheckingAccount = &checking;

	vector<Account*> accountVector;

	accountVector.push_back(&saving);
	accountVector.push_back(&checking);

	cout << "Looping through the vector and printing the account info:" << endl << endl;

	for (vector<Account*>::const_iterator it = accountVector.begin(); it != accountVector.end(); it++)
	{
		cout << (*it)->toString() << endl;
	}

	cout << "----------------------Savings------------------------" << endl;

	cout << "Processing the Savings Account:" << endl << endl;

	cout << "Adding $100 deposit" << endl << endl;
	pSavingsAccount->deposit(100);

	cout << "Calculating Interest Paid:" << endl;
	cout << saving.calculateInterestRate() << endl << endl;

	cout << "Withdrawaling $50" << endl << endl;
	try
	{
		pSavingsAccount->withdrawal(50);
	}
	catch (Withdrawal& error)
	{
		error.PrintMessage();
	}

	cout << "Withdrawaling $250" << endl;
	try
	{
		pSavingsAccount->withdrawal(250);
	}
	catch (Withdrawal& error)
	{
		error.PrintMessage();
	}

	cout << endl;

	cout << "Set Interest Rate to 0.07:" << endl;
	try
	{
		saving.SetInterestRate(0.07);
	}
	catch (InterestRate& error)
	{
		error.PrintMessage();
	}

	cout << endl;

	cout << "----------------------Checking------------------------" << endl;

	cout << "Processing the Checking Account:" << endl << endl;

	cout << "Adding $500 deposit" << endl << endl;
	pCheckingAccount->deposit(500);

	cout << "Withdrawaling $600" << endl;
	try
	{
		pCheckingAccount->withdrawal(600);
	}
	catch (Overdraft& error)
	{
		error.PrintMessage();
	}

	cout << endl;

	cout << "Setting overdraft protection equal to true" << endl << endl;
	checking.SetOverdraftProtection(1);

	cout << "Withdrawaling $600" << endl << endl;

	try
	{
		pCheckingAccount->withdrawal(600);
	}
	catch (Overdraft& error)
	{
		error.PrintMessage();
	}

	cout << "Looping through the vector and printing the account info: " << endl << endl;

	for (vector<Account*>::const_iterator it = accountVector.begin(); it != accountVector.end(); it++)
	{
		cout << (*it)->toString() << endl;
	}
	
	system("PAUSE");
	return 0;
}

