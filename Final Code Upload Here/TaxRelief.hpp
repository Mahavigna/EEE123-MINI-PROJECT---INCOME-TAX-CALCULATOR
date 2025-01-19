#pragma once 
#ifndef TAXRELIEF_HPP
#define TAXRELIEF_HPP

# include <string>

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstring>
#include <limits>
#include <fstream>
using namespace std;

// function declaration
bool askQuestion(const string& question);
int getNumberInput(const string& prompt);
void AskQuestionForSingle(int dexpenses[]);
void AskQuestionForMarried(int dexpenses[], char maritalstatus);
int calculateTotalDeductible(int dexpenses[], int size);
void displayDeductibleTable(int dexpenses[]);
void selectionexpenses();
void PrintTable(int dexpenses[]);
int getTotalRelief(); 


#endif