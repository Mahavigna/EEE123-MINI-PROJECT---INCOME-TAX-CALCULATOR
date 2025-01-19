/*
1)  Programmer      : Syuhaida Balqis Binti Mohammad Shariman
    USM email       : syublqs@student.usm.my
    GitHub username : syublqs
    Matric No.      : 23300650

2)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: Gather and calculate the sources of income of the Tax Payer.
                  Function list the income and description of income sources for user ot use during tax filling.
*/

#include "Income.hpp"
IncomeDetails income;

void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) 
    cout << ch;
    cout << endl;
}



double CalcTotalIncome(double a,  double b,  double c)
    {
    double total = income.annualSalary(income.salary) + income.businessIncome + income.dividend;
    return total;
    }


void printBill(IncomeDetails &income) { 
    int lineWidth = 80;

    cout << endl;
    printLine('=', lineWidth);
    cout << setw((lineWidth - 20) / 2) << " " << "INCOME SOURCES SUMMARY" << endl;
    printLine('=', lineWidth);

    cout << left << setw(20) << "Income" << setw(40) << "Description" << right << setw(15) << "Amount (RM)" << endl;
    printLine('-', lineWidth);
    
    if (income.salary > 0)
        cout << left << setw(20) << "Annual Salary" \
             << setw(40) << ("From " + income.companyName + " as " + income.position) \
             << right << setw(15) << fixed << setprecision(2) << income.annualSalary(income.salary) << endl;
    if (income.businessIncome > 0)
        cout << left << setw(20) << "Business" \
             << setw(40) << ("From " + income.businessType) \
             << right << setw(15) << fixed << setprecision(2) << income.businessIncome << endl;
    if (income.dividend > 0)
        cout << left << setw(20) << "Dividend" \
             << setw(40) << "From investment" \
             << right << setw(15) << fixed << setprecision(2) << income.dividend << endl;
    
    printLine('-', lineWidth);
    cout << left << setw(60) << "Total Income" << right << setw(15) << fixed << setprecision(2) << CalcTotalIncome(income.salary, income.businessIncome, income.dividend) << endl;
    printLine('=', lineWidth);
    cout << "Please press enter to continue..." <<endl;
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

string capitalize(const string& letter) {
    string result = letter; // Create a copy of the input string
    for (char &ch : result) { // Iterate over each character in the string
        ch = toupper(ch); // Convert each character to uppercase
    }
    return result; // Return the capitalized string
}

void editInformation(IncomeDetails &income, bool salarySelected, bool businessSelected, bool dividendSelected) {
    bool editSalary = false;
    bool editBusiness = false;
    bool editDividend = false;

    while (true) {
        cout << "\nEdit Information:" << endl;
        if (salarySelected) cout << "1. Edit Salary" << endl;
        if (businessSelected) cout << "2. Edit Business" << endl;
        if (dividendSelected) cout << "3. Edit Dividend" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "Please choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4 ||
            (choice == 1 && !salarySelected) || 
            (choice == 2 && !businessSelected) || 
            (choice == 3 && !dividendSelected)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        cin.ignore(); 

        switch (choice) {
            case 1: {
                cout << "\nEnter your company name: ";
                getline(cin, income.companyName);
                income.position = getValidString("Enter your position (staff, management, director, etc...): ");
                cout << "Enter your monthly salary amount in RM: ";
                income.salary = getValidAmount();
                double salary;
                salary = (income.salary * 12);
                editSalary = true;
                break;
            }
            case 2: {
                income.businessType = getValidString("\nEnter your business type and description (Goods & Services, etc...): ");
                cout << "Enter your business income amount in RM: ";
                income.businessIncome = getValidAmount();
                editBusiness = true;

                break;
            }
            case 3: {
                cout << "\nEnter your dividend amount in RM: ";
                income.dividend = getValidAmount();
                editDividend = true;
                break;
            }
            case 4:
                return;
        }
    }
}

void incomeSelection(IncomeDetails &income) {
    bool salarySelected = false;
    bool businessSelected = false;
    bool dividendSelected = false;
    bool editSelected = false;

    while (true) {
        cout << "\nIncome Selection:" << endl;
        if (!salarySelected) cout << "1. Salary" << endl;
        if(!businessSelected) cout << "2. Business" << endl;
        if (!dividendSelected) cout << "3. Dividend" << endl;  
        cout << "4. Calculate Incomes" << endl;
        cout << "5. Edit Information" << endl;
        cout << "Please choose an option (Type 1, 2, 3, 4, or 5): ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5 || 
            (choice == 1 && salarySelected) || 
            (choice == 2 && businessSelected) || 
            (choice == 3 && dividendSelected)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Already selected this option. Please try again." << endl;
            continue;
        }

        // Prevent choosing options 4 or 5 if no income data has been entered
        if ((choice == 4 || choice == 5) && 
            !salarySelected && !businessSelected && !dividendSelected) {
            cout << "Please enter at least one income source before calculating or editing." << endl;
            continue;
        }

        cin.ignore(); 

        switch (choice) {
            case 1: {
                cout << "Enter your company name: " ;
                getline(cin, income.companyName);
                income.position = getValidString("Enter your position (staff, management, director, etc...): ");
                cout << "Enter your salary amount in RM: ";
                income.salary = getValidAmount();
                salarySelected = true;
                break;
            }
            case 2: {
                income.businessType = getValidString("\nEnter your business type and description (Goods & Services, etc...): ");
                cout << "Enter your business income amount for the financial year in RM: ";
                income.businessIncome = getValidAmount();
                businessSelected = true;
                break;
            }
            case 3: {
                cout << "\nEnter your dividend amount for the financial year in RM: ";
                income.dividend = getValidAmount();
                dividendSelected = true;
                break;
            }
            case 4: {
                printBill(income);
                return;
            }
            case 5: {
                editInformation(income, salarySelected, businessSelected, dividendSelected);
                break;
            }
        }
    }
}

double getTotalIncome()
{    
    CalcTotalIncome(income.annualSalary(income.salary), income.businessIncome, income.dividend);
    return CalcTotalIncome(income.annualSalary(income.salary), income.businessIncome, income.dividend);
}

void MainIncome() {
    cout << "\n";
    printLine('=', 83);
    cout << setw((83 - 47) / 2) << " " << "< Part 2. Income Selection for Tax Calculation >" << endl;
    printLine('=', 83);
    cout << setw((83 - 50) / 2) << "Please choose your income sources and answer honestly... " << endl;

    incomeSelection(income);
    cin.ignore();

}