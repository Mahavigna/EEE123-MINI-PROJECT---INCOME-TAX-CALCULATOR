#pragma once
#ifndef CALCTOTALTAX_HPP
#define CALCTOTALTAX_HPP

void FinalTax();
void printDetailsToFile(const string& filename);

// Class for taxpayer details
class PayerOfTax {
public:
    char religion;     // Religion (I = Islam, O = Other)
    double zakat;      // Zakat/Fitrah payment
    double tax;        // Tax payable
    char pilgramage;   // Whether the user has performed pilgrimage before
    int NoTime;        // Number of times pilgrimage was performed
    double rebate;     // User Tax Rebate
    double finaltax;   // Users final Tax Payment
};

extern PayerOfTax user;

#endif