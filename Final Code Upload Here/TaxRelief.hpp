#pragma once 
#ifndef TAXRELIEF_HPP
#define TAXRELIEF_HPP

//Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstring>
#include <limits>
#include <fstream>
using namespace std;

// Function Declaration
bool askQuestion(const string& question);
double getNumberInput(const string& prompt);
void AskQuestionForSingle(double dexpenses[]);
void AskQuestionForMarried(double dexpenses[], char maritalstatus);
double calculateTotalDeductible(double dexpenses[], int size);
void displayDeductibleTable(double dexpenses[]);
void selectionexpenses();
void PrintTable(double dexpenses[]);
double getTotalRelief(); 


#endif