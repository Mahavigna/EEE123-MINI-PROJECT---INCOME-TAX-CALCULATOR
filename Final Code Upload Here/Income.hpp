#ifndef INCOME_HPP
#define INCOME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>
#include <fstream>
using namespace std;


//Function Declaration
void printLine(char ch, int length);
void MainIncome();
double CalcTotalIncome(double , double, double);
double getValidAmount();
double getTotalIncome();
string capitalize(const string& letter); 
string getValidString(const string &prompt);



//Struct for income selection
class IncomeDetails {
    public:

    string companyName;
    string position;
    string businessType;
    double salary = 0;
    double businessIncome = 0;
    double dividend = 0;

    double annualSalary(double a){
        return a * 12 ;
    }
};

extern IncomeDetails income;



#endif