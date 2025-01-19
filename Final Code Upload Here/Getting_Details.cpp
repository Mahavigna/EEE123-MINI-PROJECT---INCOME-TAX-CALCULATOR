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
void GettingDetails(User& TaxPayer, const string& initialEmail) {
    printLine('=', 83);
    cout  << setw((83 - 30) / 2) << " " << "<Part 1. Personal Details>\n";
    printLine('=', 83);
    cout << "This is only for statistical purposes.\n";
    cout << "Data can be changed after finishing filling the personal details, allowing the user to update their information if necessary\n";

    // Getting User's Name
    TaxPayer.name = getValidString("Full Name: ");

    // Getting and Validating User IC No.
    do {
        cout << "Identity Card (IC) No. (format: XXXXXX-XX-XXXX): ";
        getline(cin, TaxPayer.ic);
        if (!regex_match(TaxPayer.ic, PatternValidator::icPattern)) {
            cout << "Invalid IC No. Please Try Again.\n";
        }
    } while (!regex_match(TaxPayer.ic, PatternValidator::icPattern));

    
    do {
        cout << "Tax Identification Number (TIN): ";
        getline(cin, TaxPayer.TIN);
        if (!regex_match(TaxPayer.TIN, PatternValidator::TINPattern)) {
            cout << "Invalid TIN. Please Try Again.\n";
        }
    } while (!regex_match(TaxPayer.TIN, PatternValidator::TINPattern));

    // Getting and Validating User Phone No.
    do {
        cout << "Phone No. (format: +6[Mobile Number without dash (-)]): ";
        getline(cin, TaxPayer.phoneNo);
        if (!regex_match(TaxPayer.phoneNo, PatternValidator::phonePattern)) {
            cout << "Invalid Phone No. Please Try Again.\n";
        }
    } while (!regex_match(TaxPayer.phoneNo, PatternValidator::phonePattern));

    // Getting and Validating User Email
    do {
        cout << "Email: ";
        getline(cin, TaxPayer.email);
        if (!regex_match(TaxPayer.email, PatternValidator::emailPattern)) {
            cout << "Invalid Email. Please Try Again.\n";
        } else if (TaxPayer.email != initialEmail) {
            cout << "The entered email does not match the initial email (" << initialEmail << ").\n";
            cout << "Please re-enter the same email or confirm this is correct.\n";
        }
    } while (!regex_match(TaxPayer.email, PatternValidator::emailPattern) || TaxPayer.email != initialEmail);

    cout << "\nYour details have been collected successfully!\n";
}

// Function to update user details
void updateDetails(User& user) {
    printLine('=', 83);
    cout << setw((83 - 300) / 2) << " " << "<Update Your Details>\n";
    printLine('=', 83);
    cout << "Select the field you want to update:\n";
    cout << "1. Full name\n";
    cout << "2. Identity Card (IC) No.\n";
    cout << "3. Tax Indentification Number (TIN)\n";
    cout << "4. Phone No.\n";
    cout << "5. Email\n";
    cout << "0. Exit Update Menu\n";

    int choice;
    string newValue;

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore trailing newline from cin

        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, newValue);
                TaxPayer.name = capitalize(newValue);
                break;

            case 2:
                do {
                    cout << "Enter new IC No. (format: XXXXXX-XX-XXXX): ";
                    getline(cin, newValue);
                    if (!regex_match(newValue, PatternValidator::icPattern)) {
                        cout << "Invalid IC No. Please Try Again.\n";
                    }
                } while (!regex_match(newValue, PatternValidator::icPattern));
                TaxPayer.ic = newValue;
                break;

            case 3: 
            do {
                cout << "Tax Identification Number (TIN): ";
                getline(cin, newValue);
                if (!regex_match(newValue, PatternValidator::TINPattern)) {
                    cout << "Invalid TIN. Please Try Again.\n";
                }
            } while (!regex_match(user.TIN, PatternValidator::TINPattern));
            TaxPayer.ic = newValue;
            break;

            case 4:
                do {
                    cout << "Enter new Phone No. (format: +6[Mobile Number without dash (-)]): ";
                    getline(cin, newValue);
                    if (!regex_match(newValue, PatternValidator::phonePattern)) {
                        cout << "Invalid Phone No. Please Try Again.\n";
                    }
                } while (!regex_match(newValue, PatternValidator::phonePattern));
                user.phoneNo = newValue;
                break;

            case 5:
                do {
                    cout << "Enter new Email: ";
                    getline(cin, newValue);
                    if (!regex_match(newValue, PatternValidator::emailPattern)) {
                        cout << "Invalid Email. Please Try Again.\n";
                    }
                } while (!regex_match(newValue, PatternValidator::emailPattern));
                TaxPayer.email = newValue;
                break;

            case 0:
                cout << "Exiting update menu.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    cout << "\nYour details have been updated successfully!\n";
    PrintDetails();
}

//Get current date and time
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}

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

void TaxpayerDetails() {

    GettingDetails(TaxPayer, TaxPayer.email);
    PrintDetails();
    cout <<"\nWould like to update your information? (Yes = Y | Enter any other key for No...): ";
    char update;
    cin >> update;
    update = toupper(update);

    if (update == 'Y'){
    updateDetails(TaxPayer);
    }

}
