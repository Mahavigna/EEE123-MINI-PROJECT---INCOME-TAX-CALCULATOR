#include "FormatText.hpp"
/*
1)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624
Program Function: File contains all text formatting used in the program
*/


//Center Text
string centerText(const string& text, int width) {
    int padding = (width - text.length()) / 2; // Calculate padding on each side
    if (padding < 0) padding = 0; // Ensure padding is not negative
    return string(padding, ' ') + text + string(padding, ' ');
}

// Function to print a line of a specific symbol
void PrintFileLine(char symbol, int length, ofstream& file) {
    for (int i = 0; i < length; i++) {
        file << symbol;
    }
    file << endl;
}

// Function to convert a string to uppercase
string toUpperCase(const string& text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to format section titles
void formatSectionTitle(const string& title, int width, ofstream& file) {
    PrintFileLine('=', width, file);
    file << centerText(toUpperCase(title), width) << endl;
    PrintFileLine('=', width, file);
}

//Handle user input of string instead of integers
string getValidString(const string &prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        bool isValid = true;
        for (char ch : input) {
            if (isdigit(ch)) {
                isValid = false;
                break;
            }
        }

        if (isValid && !input.empty()) {
            for (char &ch : input) {
                ch = toupper(ch);
            }
            return input;
        } else {
            cout << "Please enter a valid input containing characters only (no numbers): " << endl;
        }
    }
}

//Capitalize string
string capitalize(const string& letter) {
    string result = letter; // Create a copy of the input string
    for (char &ch : result) { // Iterate over each character in the string
        ch = toupper(ch); // Convert each character to uppercase
    }
    return result; // Return the capitalized string
}


//Ensure using provide valid amount for income source
double getValidAmount() {
    double amount;
    while (true) {
        cin >> amount;
        if (cin.fail() || amount < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid positive number: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
    }
}

//Print Formated Header
void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) 
    cout << ch;
    cout << endl;
}

//Check for space in string
bool hasSpaces(const string& str) {
    return str.find(' ') != string::npos;
}


//Get current date and time
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}


// Function to get a valid number input
double getNumberInput(const string& prompt)
{
    double num;

    while (true)
    {
        cout << prompt;
        cin >> num;
        
        if (cin.fail() || num < 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input!!! Please enter again.\n";
        }
        else
        {
            cin.ignore(256, '\n'); // Clear the input buffer
            return num;
        }
    }
}


// Function to ask a yes/no question
bool askQuestion(const string& question)
{
    string input;

    while (true)
    {
        cout << "\n" << question << "\n";
        cout << "Y. Yes\n";
        cout << "N. No\n";
        cout << "Enter your choice (Y or N): ";
        getline(cin, input); // Read the entire line
        for (char &ch : input) {
        ch = toupper(ch);
        }

        // Check if the input is a single character and is either 'Y' or 'N'
        if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'N'))
        {
            return (input[0] == 'Y'); // Return true for 'Y'
        }
        cout << "Invalid input!!! Please enter only a single character (Y or N).\n";
    }
}

// Function to validate single character input

char getSingleCharInput(const string& prompt, const string& validChars) {
    char input;
    while (true) {
        cout << prompt;
        cin >> input;
        input = toupper(input); // Convert to uppercase for case-insensitive comparison

        // Check if the input is a Latin alphabet character
        if (!isalpha(input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a single Latin alphabet character (A-Z).\n";
            continue;
        }

        // Check if the input is one of the valid characters
        if (validChars.find(input) != string::npos) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter one of the following: ";
            for (char ch : validChars) {
                cout << ch << " ";
            }
            cout << endl;
        }
    }
    return input;
}

// Function to validate integer input
int getIntegerInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter an integer." << endl;
        }
    }
    return input;
}