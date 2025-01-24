/*EEE123-COMPUTER PROGRAMMING FOR ENGINEERS (MINI PROJECT)
Title: Malaysian Individual Income Tax Calculator
Group: 8
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
Provides an easy and user-friendly method filling Individual Assessment Income Tax for Malaysian Tax Payers. 
Program allows users to categorize their sources of income, accurately input their Tax Reliefs based on simple yes or no questions, and give tax rebates claimable by asking simple questions to ensure ease of use. 
Prints the output to a text file for ease of use and reference for users tax filing.
Reduces stress of users navigating the tax filing process.

*/

//Header files containing relevant functions and libraries
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
    TaxpayerDetails();     // Get user details (Getting_Details.cpp) 
    
    UserNameWelcome(TaxPayer.name); // Welcomes User by name (OpeningAndClosing.cpp)

    MainIncome();        // Calculates total income of user from sources specified by user (Income.cpp)

    selectionexpenses(); // Calculates User tax relief based on Yes or No questions (TaxRelief.cpp)

    displayFinalTax(); // Calculate Total Tax after rebates (CalcTotalTax.cpp)

    printDetailsToFile(TaxPayer.name); // Prints details of user or Tax Payer to a text file for easy display (CustomerData.cpp)

        // Ask if the user wants to calculate again
        cout << "\nWould you like to calculate again? (Yes = Y | Enter any key to exit...): ";
        cin >> calculateAgain;
        calculateAgain = toupper(calculateAgain);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (calculateAgain == 'Y');

    DisplayThankYou();  //Displays Thank You Message read from file 'ThankYou.txt'(OpeningAndClosing.cpp)
    return 0;
}