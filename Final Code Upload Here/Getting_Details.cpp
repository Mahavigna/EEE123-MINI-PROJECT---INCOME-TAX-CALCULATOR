/*
1)  Programmer      : CHEW CHEN WAI
    USM Email       : chenwai16@student.usm.my
    GitHub Username : chenwai1
    Matric No.      : 23301622

2)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: Get Tax Payer details to be printed in customer receipt for tax failing
*/

#include "Getting_Details.hpp"
#include "Income.hpp"
#include "TaxRelief.hpp"
#include "FormatText.hpp"


// Class to encapsulate regex patterns
class PatternValidator {
public:
    static const regex emailPattern;
    static const regex phonePattern;
    static const regex icPattern;
    static const regex TINPattern;

};

// Initialize static regex members
const regex PatternValidator::emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
const regex PatternValidator::phonePattern("^\\+60\\d{7,12}$");
const regex PatternValidator::icPattern("^\\d{6}-\\d{2}-\\d{4}$");
const regex PatternValidator::TINPattern("^[A-Za-z0-9]{10,15}$");

User TaxPayer;

// Function to get and validate user details
void GettingDetails(User& TaxPayer) {
    printLine('=', 83);
    cout  << setw((83 - 30) / 2) << " " << "<Part 1. Personal Details>\n";
    printLine('=', 83);
    cout << "This is only for statistical purposes.\n";
    cout << "Data can be changed after finishing filling the personal detail.\n";

    // Getting User's Name
    TaxPayer.name = getValidString("a) Full Name: ");

    // Getting and Validating User IC No.
    do {
        cout << "b) Identity Card (IC) No. (format: XXXXXX-XX-XXXX): ";
        getline(cin, TaxPayer.ic);
        if (!regex_match(TaxPayer.ic, PatternValidator::icPattern)) {
            cout << "Invalid IC No. Please Try Again.\n" << endl;
        }
    } while (!regex_match(TaxPayer.ic, PatternValidator::icPattern));

    
    do {
        cout << "c) Tax Identification Number (TIN): ";
        getline(cin, TaxPayer.TIN);
        if (!regex_match(TaxPayer.TIN, PatternValidator::TINPattern)) {
            cout << "Invalid TIN. Please Try Again.\n" << endl;
        }
    } while (!regex_match(TaxPayer.TIN, PatternValidator::TINPattern));

    // Getting and Validating User Phone No.
    do {
        cout << "d) Phone No. (format: +6[Mobile Number without dash (-)]): ";
        getline(cin, TaxPayer.phoneNo);
        if (!regex_match(TaxPayer.phoneNo, PatternValidator::phonePattern)) {
            cout << "Invalid Phone No. Please Try Again.\n" << endl;
        }
    } while (!regex_match(TaxPayer.phoneNo, PatternValidator::phonePattern));

    // Getting and Validating User Email
    do {
        cout << "e) Email: ";
        getline(cin, TaxPayer.email);
        if (!regex_match(TaxPayer.email, PatternValidator::emailPattern)) {
            cout << "Invalid Email. Please Try Again.\n" << endl;
        }
    } while (!regex_match(TaxPayer.email, PatternValidator::emailPattern));

    cout << "\nYour details have been collected successfully!\n";
}

//Function for user to update details
void updateDetails(User& user) {
    printLine('=', 83);
    cout << setw((83 - 30) / 2) << " " << "<Update Your Details>\n";
    printLine('=', 83);
    cout << "Select the field you want to update:\n";
    cout << "A. Full name\n";
    cout << "B. Identity Card (IC) No.\n";
    cout << "C. Tax Indentification Number (TIN)\n";
    cout << "D. Phone No.\n";
    cout << "E. Email\n";
    cout << "F. Exit Update Menu\n";

    string input;
    char choice;
    string newValue;

   do {
    cout << "\nEnter your choice: ";
    cin >> input;

    // Check if the input is a single character
    if (input.length() != 1) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a single character!\n";
        continue; // Skip the rest of the loop and prompt again
    }

    char choice = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

    // Check if the input is a valid letter (A, B, C, D, E, or F)
    if (choice < 'A' || choice > 'F') {
        cout << "Invalid choice. Please enter a letter between A and F.\n";
        continue; // Skip the rest of the loop and prompt again
    }

    cin.ignore(); // Ignore the newline character left by cin >> input

    switch (choice) {
        case 'A': {
            cout << "Enter new name: ";
            getline(cin, newValue);
            user.name = capitalize(newValue);
            cout << "Name updated successfully!\n";
            break;
        }
        case 'B': {
            do {
                cout << "Enter new IC No. (format: XXXXXX-XX-XXXX): ";
                getline(cin, newValue);
                if (!regex_match(newValue, PatternValidator::icPattern)) {
                    cout << "Invalid IC No. Please Try Again.\n";
                }
            } while (!regex_match(newValue, PatternValidator::icPattern));
            user.ic = newValue;
            cout << "IC No. updated successfully!\n";
            break;
        }
        case 'C': {
            do {
                cout << "Tax Identification Number (TIN): ";
                getline(cin, newValue);
                if (!regex_match(newValue, PatternValidator::TINPattern)) {
                    cout << "Invalid TIN. Please Try Again.\n";
                }
            } while (!regex_match(newValue, PatternValidator::TINPattern));
            user.TIN = newValue;
            cout << "TIN updated successfully!\n";
            break;
        }
        case 'D': {
            do {
                cout << "Enter new Phone No. (format: +6[Mobile Number without dash (-)]): ";
                getline(cin, newValue);
                if (!regex_match(newValue, PatternValidator::phonePattern)) {
                    cout << "Invalid Phone No. Please Try Again.\n";
                }
            } while (!regex_match(newValue, PatternValidator::phonePattern));
            user.phoneNo = newValue;
            cout << "Phone No. updated successfully!\n";
            break;
        }
        case 'E': {
            do {
                cout << "Enter new Email: ";
                getline(cin, newValue);
                if (!regex_match(newValue, PatternValidator::emailPattern)) {
                    cout << "Invalid Email. Please Try Again.\n";
                }
            } while (!regex_match(newValue, PatternValidator::emailPattern));
            user.email = newValue;
            cout << "Email updated successfully!\n";
            break;
        }
        case 'F': {
            cout << "Exiting update menu.\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    
    cout << "\nYour details have been updated successfully!\n";
    PrintDetails();
} while (toupper(input[0]) != 'F'); // Exit loop if choice is 'F'

}

//Prints User details to Terminal Formatted
void PrintDetails() {
    printLine('=', 83);
    cout << setw((83 - 30) / 2) << " " << "<Part 1. Personal Details>\n";
    printLine('=', 83);
    cout << "Date:               " << getCurrentDate() << endl;
    cout << "Name:               " << TaxPayer.name << endl;
    cout << "IC No.:             " << TaxPayer.ic << endl;
    cout << "Phone No.:          " << TaxPayer.phoneNo << endl;
    cout << "Email:              " << TaxPayer.email << endl;
    cout << "TIN:                " << TaxPayer.TIN << endl;
    printLine('=', 83);
}

//To be called in other cpp files to run functions in Getting_Details.cpp
void TaxpayerDetails() {
    GettingDetails(TaxPayer);
    PrintDetails();

    char update;
    bool validInput = false;

    // Loop until valid input is received
    while (!validInput) {
        cout << "\nWould you like to update your information? (Yes = Y | Enter any other key for No...): ";
        cin >> update;

        // Check if the input is a single character
        if (cin.peek() != '\n') {
            cout << "Invalid input. Please enter a single character!\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } else {
            validInput = true; // Input is valid
        }
    }

    update = toupper(update); // Convert to uppercase for case-insensitive comparison

    if (update == 'Y') {
        updateDetails(TaxPayer);
    } else {
        cout << "No updates will be made. Exiting...\n";
    }
}
