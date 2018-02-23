#include <iostream>
using namespace std;

class Withdrawal
{
public:
	void PrintMessage()
	{
		cout << "Error: Balance cannot be negative" << endl;
	}
};

class InterestRate
{
public:
	void PrintMessage()
	{
		cout << "Error: Interest Rate out of range" << endl;
	}
};

class Overdraft
{
public:
	void PrintMessage()
	{
		cout << "Error: Account has been overdrafted" << endl;
	}
};
