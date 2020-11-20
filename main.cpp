/****************************************
*					*
*					*
*	Banking Application		*
*					*
*       @author: Michelle Dozal		*
****************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <regex>
#include "account.h"

using namespace std;


//Function Prototypes
void intro();
void menu();
void loadRecords(vector<account>&, ifstream &);
void tokenizer(string,int&, string&, char&, double&);
void listAllAccounts(const vector<account> &);
void createNewAccount(vector<account> &, ofstream&);
void accountHolder(vector<account> &, int&, string&, char&, double&, int);
void reviewEntry(int&, string&, char&, double&);
void writeToFile(vector <account> &, ofstream&);
void displayUpdateAccount(vector<account> &, int, ofstream&);
void depositWithdraw(vector<account> &, int, ofstream &);
void validateInt(int&);
void validateType(char&);
void accountNotFound(int);
void bubbleSort(vector <account>);
bool isEmptyFile(ifstream&);
bool isAccount( const vector<account> &, int);
int findIndex(const vector <account> &, int);

int getChoice();

int main()
{

//Runs Intro Header
intro();

int choice;
vector<account> acc;
ifstream inFile;
ofstream outFile;

loadRecords(acc, inFile);

do{
menu();
choice = getChoice();

switch(choice){

case 1:
createNewAccount(acc,outFile);
break;

case 2:
system("clear");
displayUpdateAccount(acc,0,outFile);
break;

case 3:
listAllAccounts(acc);
break;

case 4:
break;

case 5:
system("clear");
displayUpdateAccount(acc,1,outFile);
break;

case 6:
depositWithdraw(acc,0,outFile);
break;

case 7:
depositWithdraw(acc,1,outFile);
break;

case 8:
cout << "\n\n";
cout << setw(50) << "Thank You for visiting! See you soon!";
cout << "\n\n";
break;
}
} while (choice != 8); 



return 0;
}

void intro()
{
///Clearing the screen just in case...
    system("clear");

    ///Application Introduction Picture
    cout << "\n\n\n" << endl;
    cout << setw(48) << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << setw(5) << "%" << setw(5) << "EURO" << "           EURO" <<
    "  YEN" << "     YEN" << "         PESOPESOPES0" << "    DOLADOLADOLA" <<
    "  LBSLBS       LBS" << "  YUAN    YUAN %" << endl;
    cout << setw(5) << "%" << setw(5) << " EURO" << " EURO" << " EURO" << " EURO"
    << "   YEN" << "   YEN" << "          PESO     PESO" << "   DOLA    DOLA" <<
    "  LBS LBS      LBS" << "  YUAN   YUAN  %" << endl;
    cout << setw(5) << "%" << setw(5) << "EURO" << "   EURO" << "    EURO"
    << "    YEN" <<
    " YEN" << "           PESO     PESO" << "   DOLA    DOLA"
    << "  LBS  LBS     LBS"
    << "  YUAN  YUAN   %"<<endl;
    cout << setw(5) << "%" << setw(5) << "EURO" << "   EURO" << "    EURO" <<
    "      YEN" << "      $$$" << "    PESOPESOPESO" << "    DOLADOLADOLA" <<
    "  LBS    LBS   LBS" << "  YUANYUAN     %" << endl;
    cout << setw(5)<< "%" << setw(5) << "EURO" << "           EURO"
    << "      YEN"
    << "             PESO      PESO" << "  DOLA    DOLA" << "  LBS      LBS LBS"
    << "  YUAN  YUAN   %" << endl;
    cout << setw(5)<< "%" << setw(5)
    << "EURO" << "           EURO" << "      YEN"
    << "             PESO     PESO" << "   DOLA    DOLA" << "  LBS       LBSLBS"
    << "  YUAN   YUAN  %" << endl;
    cout << setw(5)<< "%" << setw(5) << "EURO" << "           EURO"
    << "      YEN"
    << "             PESOPESOPESO" << "    DOLA    DOLA" << "  LBS          LBS"
    << "  YUAN    YUAN %" << endl;
    cout << setw(5) << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     " << endl;
    ///color change
    
    cout << setw(5) << "    $                                                  "
    "                                                     $" << endl;
    cout << setw(8) << "    $                                       "
    "     Banking Application                       "
    "                 $" << endl;
    cout << setw(8) << "    $                                                  "
    "                                                     $" << endl;
    cout << setw(8) << "    $                                 AUTHOR: MICHEllE "
    "DOZAL                                                $" << endl;
    cout << setw(8) << "    $                                                  "
    "                                                     $" << endl;
    cout << setw(8) << "    $                                                  "
    "                                                     $" << endl;
    cout << setw(8) << "    $                                                  "
    "                                                     $" << endl;
    cout << setw(8) << "    $                                       "
    "        Version 6.0.9"
    "                                           $" << endl;
    cout << setw(8) << "    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << endl << endl;
    cout << setw(8) << " " << "Press Enter to Continue...";
    cin.ignore();
}

void menu() {

system("clear");
cout << "\n\n\n" << endl;

cout << setw(60) << "Main Menu" << endl;
   cout << setw(68) << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << setw(60) <<  "\n" << endl;
   cout << setw(66) << "1. Create a New Account" << endl;
   cout << setw(64) << "2. Display an Account" << endl;
   cout << setw(63) << "3. List All Accounts" << endl;
   cout << setw(80) << "4. List All Accounts, Sorted by Names" << endl;
   cout << setw(60) << "5. Update Account" << endl;
   cout << setw(60) << "6. Make a Deposit" << endl;
   cout << setw(60) << "7. Withdraw Money" << endl;
   cout << setw(62) << "8. Exit the Program" << endl;
   cout << setw(60) << "\n" << endl;
}

int getChoice(){

int choice;

cout << setw(43) << " " << "Enter Your Choice: ";
cin >> choice;

//input validation
while ((1 > choice) || (choice > 8 ) || cin.fail() ){
cout << setw(43) << " " << "ERROR! Valide Entry is 1 - 8. Re-Enter: ";
cin.clear();
cin.ignore(numeric_limits<int>::max(), '\n');
cin >> choice;
}
	return choice;
}

void loadRecords(vector<account> &v, ifstream &f){

account acc;
int accNo;
string name, str;
char ch;
double bal;

f.open("records.txt");

if(!f){
system("clear");
cout << "\n\n";
    cout << setw(50) << "ERROR! Could not open file" << endl;
    cout << setw(50) << "File Might Not Exist Or..." << endl;
    cout << setw(50) << "Wrong File name is used....." << endl;
    cout << setw(50) << "Exit Program for ERROR check" << endl;
    cout << endl << endl << endl;
    exit(0);
    }
else if(isEmptyFile(f)){
system("clear");
    cout << "\n\n\n";
    cout << setw(50) << "There Are No Records on File" << endl;
    cout << setw(50) << "Start loading records to File" << endl;
    cout << setw(50) << " ";
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get()
    return ;
}

else{
f.close();
f.open("records.txt");

}

do{
getline(f,str);
if(!f.eof())
      { tokenizer(str,accNo,name,ch,bal);
        acc.setAccountNo(accNo);
        acc.setName(name);
        acc.setType(ch);
        acc.setBalance(bal);
        v.push_back(acc);
       }

    } while (!f.eof());

}
void createNewAccount(vector<account> &v, ofstream &out){

int accNo;
string name;
char ch;
double bal;
account acc;

accountHolder(v, accNo, name, ch, bal, 0);

reviewEntry(accNo, name, ch, bal);

acc.setAccountNo(accNo);
acc.setName(name);
acc.setType(ch);
acc.setBalance(bal);

v.push_back(acc);
writeToFile(v,out);

cout << setw(13) << " " << "Account written to file" << endl << endl;
cin.clear();
cin.ignore(numeric_limits<int>::max(), '\n');
cin.get()
}

void accountHolder(vector<account> &v, int &accNo, string &name, char &ch, double &bal, int flag){

cout << "\n\n\n";

if(flag == 0){
	cout << setw(13) << " " << "Enter Account Number............: ";
	cin >> setw(4) >> accNo;
	validateInt(accNo);


	while(isAccount(v,accNo)){

	cout << setw(13) << " " << "Account Number Is ALready In Use. Re-Enter.....: ";
	cin >> accNo;
	validateInt(accNo);
	}
}
else if(flag == 1){
	cin.clear();
	cin.ignore(numeric_limits<int>::max(), '\n');
}

	cout << setw(13) << " " << "Account Name..........................: ";
	 getline(cin, name);

   	cout << setw(13) << " " << "Account Type..........................: ";
    	cin >> ch;
     	ch = toupper(ch);
     	validateType(ch);

   	cout << setw(13) << " " << "Account Balance.......................: ";
    	cin >> bal;
}

void reviewEntry(int &accNo, string &name, char &ch, double &bal)
{

	cout << "\n\n\n";
	cout << setw(13) << " " << "Account Number......................: "
         << accNo << endl;
    	cout << setw(13) << " " << "Account Name........................: "
         << name << endl;
    	cout << setw(13) << " " << "Account Type........................: "
         << ch << endl;
    	cout << setw(13) << " " << "Account Balance.....................: "
         << bal << endl;

	cin.clear();
cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get();
}

void writeToFile(vector <account> &v, ofstream &out){

out.open("records.txt");


if(!out){
system("clear");
cout << "\n\n";
    cout << setw(50) << "ERROR! Could not open file" << endl;
    cout << setw(50) << "File Might Not Exist Or..." << endl;
    cout << setw(50) << "Wrong File name is used....." << endl;
    cout << setw(50) << "Exit Program for ERROR check" << endl;
    cout << endl << endl << endl;
    exit(0);
        }
for(size_t i = 0; i < v.size(); i++){
	out << v[i].getAccountNo() << "/" << v[i].getName() << "/"
	    << v[i].getType() << "/" << v[i].getBalance() << endl;
}

}

void displayUpdateAccount(vector <account> &v, int flag, ofstream &out){

system("clear");

account acc;
int accNo, index;
string name;
char ch;
double bal;


cout << "\n\n\n";
cout << setw(13) << " " <<  "Enter an Account Number to display....: ";
cin >> accNo;

if(isAccount(v,accNo)){
index = findIndex(v,accNo);
}

else{
accountNotFound(accNo);
return;
}

name = v[index].getName();
ch = v[index].getType();
bal = v[index].getBalance();


if (flag == 0){
            reviewEntry(accNo, name, ch, bal);
            cout << endl << endl;
            cout << setw(13) << " ";
          cin.clear();
cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get();  
	//system("pause");
            return;
        }
else if(flag == 1){
            reviewEntry(accNo, name, ch, bal);
            accountHolder(v,accNo,name,ch,bal,1);

            acc.setAccountNo(accNo);
            acc.setName(name);
            acc.setType(ch);
            acc.setBalance(bal);

            v[index] = acc;
            writeToFile(v, out);
            return;
        }

}
void depositWithdraw(vector<account> &v, int flag, ofstream &out)
{
   account  acc;
   int      accNo, index;
   string   name;
   char     ch;
   double   bal, money;

   
   cout << "\n\n\n";
   cout << setw(13) << " " << "Enter an Account Number..............: ";
    cin >> accNo;
   validateInt(accNo);

   if(isAccount(v, accNo)){
    index = findIndex(v, accNo);
   }
   else{
    accountNotFound(accNo);
    return;
   }
   name = v[index].getName();
     ch = v[index].getType();
    bal = v[index].getBalance();

 
    if(flag == 0){
        system("clear");
        cout << "\n\n\n";
        cout << setw(13) << " " << "Current Balance for..................: "
             << name << endl << endl;
        cout << setw(30) << "$" << setw(11) << bal << endl << endl;
        cout << setw(13) << " " << "Enter the Amount to Deposit..........: ";
         cin >> money;
         bal += money;
        cout << setw(13) << " " << "New Balance for......................: "
             << name << endl << endl;
        cout << setw(30) << "$" << setw(11) << bal << endl << endl;
        cout << setw(13) << " ";
        cin.clear();
	cin.ignore(numeric_limits<int>::max(), '\n');
	cin.get()
    }
   
    else if (flag == 1)
    {  system("clear");
        cout << "\n\n\n";
        cout << setw(13) << " " << "Current Balance for..................: "
             << name << endl << endl;
        cout << setw(30) << "$" << setw(11) << bal << endl << endl;
        cout << setw(13) << " " << "Enter the Amount to Withdraw.........: ";
         cin >> money;
         bal -= money;
        cout << setw(13) << " " << "New Balance for......................: "
             << name << endl << endl;
        cout << setw(30) << "$" << setw(11) << bal << endl << endl;
        cout << setw(13) << " ";
        cin.clear();
	cin.ignore(numeric_limits<int>::max(), '\n');
	cin.get()
    }
        reviewEntry(accNo, name, ch, bal);
        acc.setAccountNo(accNo);
        acc.setName(name);
        acc.setType(ch);
        acc.setBalance(bal);

      
        v[index] = acc;
        writeToFile(v, out);
        cout << endl << endl;
        cout << setw(13) << " " << "Account Updated...." << endl << endl;
        cout << setw(13) << " ";
        cin.clear();
	cin.ignore(numeric_limits<int>::max(), '\n');
	cin.get()
}

bool isAccount(const vector <account> &v, int accNo)
{   ///checks the whole vector of account to see if the account number
    ///entered exists within the vector
    for (size_t i = 0; i < v.size(); i++){
        if(v[i].getAccountNo() == accNo){
            return true;
        }
    }
            return false;
}

int findIndex(const vector <account> &v, int accNo)
{    int index;
     ///checks the whole vector of account
     for (size_t i = 0; i < v.size(); i++){
        ///if the account number is there it sets the index equal to the space
        if(v[i].getAccountNo() == accNo){
            index = i;
        }
    }
            return index;
}

void validateInt(int &n)
{
    while (n < 0 || cin.fail())
    {
       cout << setw(13) << " "
            << "ERROR!!" << endl
            << setw(13) << " "
            << "4 Positive Whole Numbers Only " << endl
            << setw(13) << " "
            << "Re-Enter..............................: ";
       cin.clear();
       cin.ignore(numeric_limits<int>::max(),'\n');
       cin >> n;
    }
       cin.clear();
       cin.ignore(numeric_limits<int>::max(),'\n');
	cin.get();
}
void validateType(char &ch)
{   
    string strCh(1, ch);
     regex integer("^(?:C|c|S|s)?");

     while(!(regex_match(strCh, integer))){
        cout << setw(13) << " " << "Wrong Input. Please Enter C/s or S/s..: ";
         cin >> strCh;
         if(regex_match(strCh, integer)){
            break;
         }
    }
     ch = strCh[0];
}
void accountNotFound(int accNo)
{
    cout << setw(13) << " " << "There are no Accounts with Account Number: " << accNo << endl;
    cout << setw(13) << " " << "Try another Account Number!!" << endl << endl;
    cout << setw(13) << " ";
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get();
}

bool isEmptyFile(ifstream &f)
{   f.seekg(0, ios::end);
    size_t pos = f.tellg();
    if (pos == 0){
        f.close();
        return true;
    }
    f.close();
    return false;
}

void listAllAccounts(const vector<account> &v)
{
   system("clear");

   cout << "\n\n\n";
   cout << setw(50) << "LIST ALL ACCOUNTS" << endl;
   cout << setw(50) << "_________________" << endl << endl;

   cout << fixed << showpoint << setprecision(2);
   cout << setw(13) << " " << setw(5) << "Account No" << setw(10)
        << "Name" << setw(25) << "Type" << setw(7) << right << setw(20)
        << "Balance" << endl;

 cout << setw(13) << " " << "________________________________________________" <<  "__________________" << endl << endl;

   if(v.size() == 0)
   {
       cout << setw(50) << "There are no records to display" << endl;
       cout << endl;
       cout << setw(50) << "";
       cin.clear();
       cin.ignore(numeric_limits<int>::max(), '\n');
       cin.get()
       return;
   }
  for (size_t i = 0; i < v.size(); i++)
  {
    cout << setw(13) << " "
         << setw(7) << left << v[i].getAccountNo()
         << setw(9) << " " << right << v[i].getName()
         << setw(14)  << v[i].getType()
         << setw(15) << "$" << setw(2)  << v[i].getBalance() << endl;
  }
    cout << endl << endl;
    cout << setw(15) << " ";
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
    cin.get();
 
}
void tokenizer(string str, int &accNo, string &name, char &ch, double &bal)
{
    size_t length = str.length();
    size_t pos1 = str.find_first_of('/');
    size_t pos2 = str.find_first_of('/',pos1 + 1);
    size_t pos3 = str.find_first_of('/', pos2 + 1);

    string strNo = str.substr(0, pos1);
   accNo = stoi(strNo);

    name = str.substr(pos1 + 1, (pos2 - pos1) - 1 );


    string strCh = str.substr(pos2 + 1, (pos3 - pos2) - 1);
    ch = strCh[0];

    string strbal = str.substr(pos3 + 1, (length - pos3) - 1);
    bal = stod(strbal);
}
