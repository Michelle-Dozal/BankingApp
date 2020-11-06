#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

using namespace std;

class account
{

public:

account();
account(int,string,char,double);

void setAccountNo(int);
void setName(string);
void setType(char);
void setBalance(double);

int getAccountNo () const;
string getName () const;
char getType () const;
double getBalance () const;


private:

int accountNo;
string name;
char type;
double balance;

};

#endif //ACCOUNT_H
