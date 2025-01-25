#pragma once 
#ifndef GETTING_DETAILS_HPP
#define GETTING_DETAILS_HPP

//Header Files used
#include <iostream>
#include <limits>
#include <regex>
using namespace std;


// Define the User structure
struct User {
    string name;
    string ic;
    string TIN;
    string phoneNo;
    string email;
};

extern User TaxPayer;

//Function Declaration
void TaxpayerDetails();
void printDetailsToFile(const string& filename);
string getCurrentDate();
void PrintDetails();

#endif