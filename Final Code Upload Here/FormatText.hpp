#pragma once
#ifndef FORMATTEXT_HPP
#define FORMATTEXT_HPP

//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

//Function Declaration
bool askQuestion(const string& question);
string centerText(const string& text, int width);
void PrintFileLine(char symbol, int length, ofstream& file);
string toUpperCase(const string& text);
void formatSectionTitle(const string& title, int width, ofstream& file);
string getValidString(const string &prompt);
string capitalize(const string& letter);
double getValidAmount();
void printLine(char ch, int length);
bool hasSpaces(const string& str);
string getCurrentDate();
double getNumberInput(const string& prompt);
bool askQuestion(const string& question);
int getIntegerInput(const string& prompt);
char getSingleCharInput(const string& prompt, const string& validChars);




#endif