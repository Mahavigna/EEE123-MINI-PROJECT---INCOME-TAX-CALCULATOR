#pragma once 
#ifndef LOGIN_REGISTER_HPP
#define LOGIN_REGISTER_HPP

//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Income.hpp"
#include "Getting_Details.hpp"
using namespace std;


//Function Declaration
void registerUser();
bool loginUser();
void MainMenu();
void WelcomeMsg(const string& name);
void mainloop();





#endif