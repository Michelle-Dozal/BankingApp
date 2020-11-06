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


int main()
{


intro();


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
