#pragma once
#ifndef CALCTOTALTAX_HPP
#define CALCTOTALTAX_HPP


//Libraries
#include <iostream>
#include <iomanip>
#include <string>

//Function Declaration
void displayFinalTax();
void printDetailsToFile(const string& filename);
double Rebate();
double calculateTax(double chargeableIncome);

// Class for taxpayer details
class PayerOfTax {
public:
    char religion;     // Religion (I = Islam, O = Other)
    double zakat;      // Zakat/Fitrah payment
    double tax;        // Tax payable
    char pilgrimage;   // Whether the user has performed pilgrimage before
    int NoTime;        // Number of times pilgrimage was performed
    double rebate;     // User Tax Rebate
    double finaltax;   // Users final Tax Payment
};

//Global Variables
extern PayerOfTax user;

#endif