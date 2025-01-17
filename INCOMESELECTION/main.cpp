//Programmer : Syuhaida Balqis Binti Mohammad Shariman
//USM email : syublqs@student.usm.my
//GitHub username : syublqs
//Matric No.: 23300650


#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

struct IncomeDetails {
    string companyName;
    string position;
    string businessType;
    double salary = 0;
    double businessIncome = 0;
    double dividend = 0;
};

void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) cout << ch;
    cout << endl;
}

void printBill(const IncomeDetails &income) {
    double total = income.salary + income.businessIncome + income.dividend;
    int lineWidth = 80;

    cout << endl;
    printLine('=', lineWidth);
    cout << setw((lineWidth - 18) / 2) << " " << "TAX INCOME BILL" << endl;
    printLine('=', lineWidth);

    cout << left << setw(20) << "Income" << setw(40) << "Description" << right << setw(15) << "Amount (RM)" << endl;
    printLine('-', lineWidth);
    
    if (income.salary > 0)
        cout << left << setw(20) << "Salary" \
             << setw(40) << ("From " + income.companyName + " as " + income.position) \
             << right << setw(15) << fixed << setprecision(2) << income.salary << endl;
    if (income.businessIncome > 0)
        cout << left << setw(20) << "Business" \
             << setw(40) << ("From " + income.businessType) \
             << right << setw(15) << fixed << setprecision(2) << income.businessIncome << endl;
    if (income.dividend > 0)
        cout << left << setw(20) << "Dividend" \
             << setw(40) << "From investment" \
             << right << setw(15) << fixed << setprecision(2) << income.dividend << endl;
    
    printLine('-', lineWidth);
    cout << left << setw(60) << "Total Income" << right << setw(15) << fixed << setprecision(2) << total << endl;
    printLine('=', lineWidth);
}

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
            return input;
        } else {
            cout << "Please enter a valid input containing characters only (no numbers): " << endl;
        }
    }
}

void editInformation(IncomeDetails &income) {
    while (true) {
        cout << "\nEdit Information:" << endl;
        cout << "1. Edit Salary" << endl;
        cout << "2. Edit Business" << endl;
        cout << "3. Edit Dividend" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Please choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        cin.ignore(); 

        switch (choice) {
            case 1: {
                income.companyName = getValidString("\nEnter your company name: ");
                income.position = getValidString("Enter your position: ");
                cout << "Enter your salary amount in RM: ";
                income.salary = getValidAmount();
                break;
            }
            case 2: {
                income.businessType = getValidString("\nEnter your business type: ");
                cout << "Enter your business income amount in RM: ";
                income.businessIncome = getValidAmount();
                break;
            }
            case 3: {
                cout << "\nEnter your dividend amount in RM: ";
                income.dividend = getValidAmount();
                break;
            }
            case 4:
                return;
        }
    }
}

void incomeSelection(IncomeDetails &income) {
    while (true) {
        cout << "\nIncome Selection:" << endl;
        cout << "1. Salary" << endl;
        cout << "2. Business" << endl;
        cout << "3. Dividend" << endl;
        cout << "4. Calculate Incomes" << endl;
        cout << "5. Edit Information" << endl;
        cout << "Please choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        cin.ignore(); 

        switch (choice) {
            case 1: {
                income.companyName = getValidString("\nEnter your company name: ");
                income.position = getValidString("Enter your position: ");
                cout << "Enter your salary amount in RM: ";
                income.salary = getValidAmount();
                break;
            }
            case 2: {
                income.businessType = getValidString("\nEnter your business type: ");
                cout << "Enter your business income amount in RM: ";
                income.businessIncome = getValidAmount();
                break;
            }
            case 3: {
                cout << "\nEnter your dividend amount in RM: ";
                income.dividend = getValidAmount();
                break;
            }
            case 4: {
                printBill(income);
                return;
            }
            case 5: {
                editInformation(income);
                break;
            }
        }
    }
}

int main() {
    IncomeDetails income;

    cout << "\n";
    printLine('=', 60);
    cout << setw((60 - 47) / 2) << " " << "Welcome to Income Selection for Tax Calculation" << endl;
    printLine('=', 60);

    incomeSelection(income);

    return 0;
}

