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

using namespace std;


//Function Prototypes
void intro();
void menu();
void loadRecords(vector<account>&, ifstream &);


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
system("cls");
displayUpdateAccount(acc,0,outFile);
break;

case 3:
listAllAccounts(acc);
break;

case 4:
break;

case 5:
system("cls");
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
    system("cls");

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

system("cls");
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
string name;
char ch;
double bal;

f.open("records.txt");

if(!f){
system("cls");
cout << "\n\n";
    cout << setw(50) << "ERROR! Could not open file" << endl;
    cout << setw(50) << "File Might Not Exist Or..." << endl;
    cout << setw(50) << "Wrong File name is used....." << endl;
    cout << setw(50) << "Exit Program for ERROR check" << endl;
    cout << endl << endl << endl;
    exit(0);
    }
else if(isEmptyFile(f)){
system("cls");
    cout << "\n\n\n";
    cout << setw(50) << "There Are No Records on File" << endl;
    cout << setw(50) << "Start loading records to File" << endl;
    cout << setw(50) << " ";
    system("pause");
    return 0;
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

    } while (!f.eof());}

}
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
system("pause");
}

void accountHolder(vector<account> &v, int &accNo, string &name, char &ch, double &bal, int flag){

cout << "\n\n\n";

if(flag == 0){
	cout << setw(13) << " " << "Enter Account Number............: ";
	cin >> accNo;
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
}



}


