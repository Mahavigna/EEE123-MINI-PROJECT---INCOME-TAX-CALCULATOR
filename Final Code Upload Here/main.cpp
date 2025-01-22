/*EEE123-COMPUTER PROGRAMMING FOR ENGINEERS (MINI PROJECT)
Title: Malaysian Individual Income Tax Calculator
Group: 
1)  Programmer     : OOI YEEZON
    USM Email      : yeezon@student.usm.my
    GitHub Username: yeezon1
    Matric No.     : 23301291

2)  Programmer      : CHEW CHEN WAI
    USM Email       : chenwai16@student.usm.my
    GitHub Username : chenwai1
    Matric No.      : 23301622

3)  Programmer      : Syuhaida Balqis Binti Mohammad Shariman
    USM email       : syublqs@student.usm.my
    GitHub username : syublqs
    Matric No.      : 23300650

4)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: 

*/

//Header files containing relevent functions and libraries
#include "Income.hpp"
#include "TaxRelief.hpp"
#include "CalcTotalTax.hpp"
#include "Getting_Details.hpp"
#include "FormatText.hpp"
#include "OpeningAndClosing.hpp"

//Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

//Function Declaration
void TaxpayerDetails(); 
void selectionexpenses();
void displayFinalTax();
void printDetailsToFile(const string& filename); 
void WelcomeMsg(); 
void DisplayThankYou();
void UserNameWelcome(const string& name);

int main(){

    WelcomeMsg(); //Welcomes user to Program

char calculateAgain;


    do{
    TaxpayerDetails();     // Get user details 
    
    UserNameWelcome(TaxPayer.name); // Welcomes User by name

    MainIncome();        // Calculates total income of user from sources specified by user (Income.cpp)

    selectionexpenses(); // Calculates User tax relief based on Yes or No questions (TaxRelief.cpp)

    displayFinalTax(); // Calculate Total Tax after rebates

    printDetailsToFile(TaxPayer.name); // Prints details of user or Tax Payer to a text file for easy display

        // Ask if the user wants to calculate again
        cout << "\nWould you like to calculate again? (Yes = Y | Enter any key to exit...): ";
        cin >> calculateAgain;
        calculateAgain = toupper(calculateAgain);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (calculateAgain == 'Y');

    DisplayThankYou();
    return 0;
}