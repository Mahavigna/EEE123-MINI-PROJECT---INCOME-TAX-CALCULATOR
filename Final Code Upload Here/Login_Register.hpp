#pragma once 
#ifndef LOGIN_REGISTER_HPP
#define LOGIN_REGISTER_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Income.hpp"
#include "Getting_Details.hpp"


void registerUser();
bool loginUser();
void MainMenu();
bool hasSpaces(const string& str);
void WelcomeMsg(const string& name);
string centerText(const string& text, int width);
void mainloop();


using namespace std;



#endif