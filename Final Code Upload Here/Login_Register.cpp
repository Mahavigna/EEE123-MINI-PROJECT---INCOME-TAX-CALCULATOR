/*
1)  Programmer      : CHEW CHEN WAI
    USM Email       : chenwai16@student.usm.my
    GitHub Username : chenwai1
    Matric No.      : 23301622

2)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: Login system to ensure only registered user can use the application
*/

#include "main.hpp"
#include "Income.hpp"
#include "TaxRelief.hpp"
#include "Login_Register.hpp"
#include "CalcTotalTax.hpp"
#include "CustomerData.hpp"

bool hasSpaces(const string& str) {
    return str.find(' ') != string::npos;
}

void MainMenu() {
    int choice;
    int linewidth = 83;


    printLine('=', linewidth);
    cout << "\033[1;36m"; // Cyan color
    cout << centerText("Welcome to APEX Individual Income Tax Calculator", 80) << endl;
    cout << "\033[0m"; // Reset color
    printLine('=', linewidth);
    
    // Disclaimer
    cout << "\033[1;33m"; // Yellow color
    cout << centerText("Disclaimer:", 80) << endl;
    cout << "\033[0m"; // Reset color
    cout << centerText("This is an INDIVIDUAL income tax calculator that does not support joint assessment.", 80) << endl;
    cout << centerText("Please answer honestly as the program relies on your input.", 80) << endl;
    printLine('=', linewidth);



    while (true) {
    // Section separator
    cout <<"\n";
    printLine('=', linewidth);
    cout << setw((linewidth - 40) / 2) << " " << "< Part 0. Login for APEX Tax Calculator >" << endl;
    printLine('=', linewidth);
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            if (loginUser()) {
                cout << "Please press enter to continue..." << endl;
                cin.ignore();
                mainloop();
                break;
            } else {
                cout << "Login failed. Please try again.\n";
            }
        } else if (choice == 3) {
            cout << "Thanks for using the calculator. Goodbye!\n";
            break;
        } else if (cin.fail()) {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}

void registerUser() {
    string username, password, fileUsername, filePassword;
    ifstream inputfile;
    ofstream outputfile;

    while (true) {
        cout << "\nRegister:\n";
        cout << "Enter a username (no spacing, type 'exit' to go back): ";
        getline(cin, username);

        if (username == "exit") {
            cout << "Returning to the main menu...\n";
            return;
        }

        if (hasSpaces(username) || username.empty()) {
            cout << "Error: Username cannot contain spaces or be empty.\n";
            continue;
        }

        inputfile.open("credentials.csv");
        bool userExists = false;
        
        if (inputfile.is_open()) {
            string line;
            while (getline(inputfile, line)) {
                size_t commaPos = line.find(',');
                if (commaPos != string::npos) {
                    fileUsername = line.substr(0, commaPos);
                    if (fileUsername == username) {
                        userExists = true;
                        break;
                    }
                }
            }
            inputfile.close();
        }

        if (userExists) {
            cout << "The username already exists. Please choose a different username.\n";
            continue;
        }

        cout << "Enter a password (no spacing, type 'exit' to go back): ";
        getline(cin, password);

        if (password == "exit") {
            cout << "Returning to the main menu...\n";
            return;
        }

        if (hasSpaces(password) || password.empty()) {
            cout << "Error: Password cannot contain spaces or be empty.\n";
            continue;
        }

        outputfile.open("credentials.csv", ios::app);
        if (outputfile.is_open()) {
            outputfile << username << "," << password << endl;
            outputfile.close();
            cout << "Registration successful!\n";
            break; 
        } else {
            cout << "Error: Unable to save credentials. Please try again.\n";
        }
    }
}

bool loginUser() {
    string username, password, fileUsername, filePassword;
    ifstream inputfile;

    while (true) {
        cout << "\nLogin:\n";
        cout << "Enter your username (type 'exit' to go back): ";
        getline(cin, username);

        if (username == "exit") {
            cout << "Returning to the main menu...\n";
            return false;
        }

        cout << "Enter your password (type 'exit' to go back): ";
        getline(cin, password);

        if (password == "exit") {
            cout << "Returning to the main menu...\n";
            return false;
        }

        inputfile.open("credentials.csv");
        if (inputfile.is_open()) {
            bool loginSuccessful = false;

            string line;
            while (getline(inputfile, line)) {
                size_t commaPos = line.find(',');
                if (commaPos != string::npos) {
                    fileUsername = line.substr(0, commaPos);
                    filePassword = line.substr(commaPos + 1);

                    if (username == fileUsername && password == filePassword) {
                        loginSuccessful = true;
                        break;
                    }
                }
            }

            inputfile.close();

            if (loginSuccessful) {
                cout << "\nLogin successful!\n";
                WelcomeMsg(username);
                return true;
            } else {
                cout << "Invalid username or password. Please try again.\n";
            }
        } else {
            cout << "Error: Unable to open the credentials file.\n";
            return false;
        }
    }
}


string centerText(const string& text, int width) {
    int padding = (width - text.length()) / 2; // Calculate padding on each side
    if (padding < 0) padding = 0; // Ensure padding is not negative
    return string(padding, ' ') + text + string(padding, ' ');
}


//Function Prints Welcome Message for User Logging In 
void WelcomeMsg(const string& name) {
    time_t now = time(0);
    string loginTime = ctime(&now); // Get the current time as a string

    // Remove the newline character from the login time
    loginTime.erase(loginTime.find_last_not_of('\n') + 1);

    int tableWidth = 83; // Total width of the table

    // Construct the welcome message
    string welcomeMessage = "Welcome, " + name + "!";
    string loginMessage = "Login Time: " + loginTime;

    // Center the welcome message and login time
    string centeredWelcome = centerText(welcomeMessage, tableWidth - 2); // Subtract 2 for borders
    string centeredLogin = centerText(loginMessage, tableWidth - 2); // Subtract 2 for borders

    // Print the top border of the table
    printLine('=', tableWidth);

    // Print the centered welcome message
    cout << "|" << centeredWelcome << " |" << endl;

    // Print the centered login time
    cout << "|" << centeredLogin << "|" << endl;

    // Print the bottom border of the table
    printLine('=', tableWidth);
}


void mainloop(){

    char calculateAgain;

    do{

    TaxpayerDetails();     // Get user details 

    MainIncome();        // Calculates total income of user from sources specified by user (Income.cpp)

    selectionexpenses(); // Calculates User tax relief based on Yes or No questions (TaxRelief.cpp)

    FinalTax(); // Calculate Total Tax after rebates

    printDetailsToFile(TaxPayer.name); // Prints details of user or Tax Payer to a text file for easy display

        // Ask if the user wants to calculate again
        cout << "\nWould you like to calculate again? (Yes = Y / Enter any key for No...): ";
        cin >> calculateAgain;
        calculateAgain = toupper(calculateAgain);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (calculateAgain == 'Y');

    cout << "\nThank you for using APEX Individual Income Tax Calculator!" <<endl;
}