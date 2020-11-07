#include "account.h"

account::account()
{
	accountNo = 0;
	name = "";
	type = 0;
	balance = 0.0;

}

account::account(int accountNo, string name, char type, double balance)
{
	this -> accountNo = accountNo;
	this -> name = name;
	this -> type = type;
	this -> balance = balance;
}

void account::setAccountNo(int accountNo)
{
	this -> accountNo = accountNo;

}

void account::setName(string name)
{
    this -> name = name;
}

void account::setType(char type)
{
    this -> type = type;
}

void account::setBalance(double balance)
{
    this -> balance = balance;
}

int account::getAccountNo() const
{
    return accountNo;
}

string account::getName() const
{
    return name;
}

char account::getType() const
{
    return type;
}

double account::getBalance() const
{
    return balance;
}

