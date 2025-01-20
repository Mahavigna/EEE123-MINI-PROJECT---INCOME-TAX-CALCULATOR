#ifndef INCOME_HPP
#define INCOME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>
#include <fstream>
using namespace std;


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


//Function Declaration
void MainIncome();
double CalcTotalIncome(double , double, double);
double getTotalIncome();
void printBill(IncomeDetails &income);
void editInformation(IncomeDetails &income, bool salarySelected, bool businessSelected, bool dividendSelected);
void incomeSelection(IncomeDetails &income);  






#endif