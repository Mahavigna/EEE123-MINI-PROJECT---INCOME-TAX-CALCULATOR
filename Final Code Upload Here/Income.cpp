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
#include "FormatText.hpp"

IncomeDetails income;

//Calculate Total income from sources
double CalcTotalIncome(double a,  double b,  double c)
    {
    double total = income.annualSalary(income.salary) + income.businessIncome + income.dividend;
    return total;
    }

//Pint Income Summary
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
    cout <<"\n\n"<< endl;
}

//Allow user to edit income information
void editInformation(IncomeDetails &income, bool salarySelected, bool businessSelected, bool dividendSelected) {
    while (true) {
        cout << "\nEdit Information:" << endl;
        if (salarySelected) cout << "A. Edit Salary" << endl;
        if (businessSelected) cout << "B. Edit Business" << endl;
        if (dividendSelected) cout << "C. Edit Dividend" << endl;
        cout << "D. Return to Main Menu" << endl;
        cout << "Please choose an option: ";

        string editchoice;
        cin >> editchoice;

        // Check if the input is exactly one character
        if (editchoice.length() != 1) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter only one character!" << endl;
            continue; // Skip the rest of the loop and prompt again
        }

        char choice = toupper(editchoice[0]); // Convert to uppercase for case-insensitive comparison

        // Input validation for choice
        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' ||
            (choice == 'A' && !salarySelected) || 
            (choice == 'B' && !businessSelected) || 
            (choice == 'C' && !dividendSelected)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid option. Please try again." << endl;
            continue; // Skip the rest of the loop and prompt again
        }

        cin.ignore(); // Ignore the newline character left by cin >> input

        switch (choice) {
            case 'A': {
                cout << "\nEnter your company name: ";
                getline(cin, income.companyName);
                income.position = getValidString("Enter your position (staff, management, director, etc...): ");
                cout << "Enter your monthly salary amount in RM: ";
                income.salary = getValidAmount();
                cout << "Salary information updated successfully!" << endl;
                break;
            }
            case 'B': {
                income.businessType = getValidString("\nEnter your business type and description (Goods & Services, etc...): ");
                cout << "Enter your business income amount in RM: ";
                income.businessIncome = getValidAmount();
                cout << "Business information updated successfully!" << endl;
                break;
            }
            case 'C': {
                cout << "\nEnter your dividend amount in RM: ";
                income.dividend = getValidAmount();
                cout << "Dividend information updated successfully!" << endl;
                break;
            }
            case 'D':
                cout << "Returning to the main menu..." << endl;
                return; // Exit the function and return to the main menu
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

//Allow user to select and input income information
void incomeSelection(IncomeDetails &income) {
    cout << "\n";
    printLine('=', 83);
    cout << setw((83 - 47) / 2) << " " << "< Part 2. Income Selection for Tax Calculation >" << endl;
    printLine('=', 83);
    cout << setw((83 - 50) / 2) << "Please choose your income sources and answer honestly... " << endl;
    bool salarySelected = false;
    bool businessSelected = false;
    bool dividendSelected = false;

    while (true) {
        cout << "\nIncome Selection:" << endl;
        if (!salarySelected) cout << "A. Salary" << endl;
        if (!businessSelected) cout << "B. Business" << endl;
        if (!dividendSelected) cout << "C. Dividend" << endl;
        cout << "D. Calculate Incomes" << endl;
        cout << "E. Edit Information" << endl;
        cout << "Please choose an option (Type A, B, C, D, or E): ";

        string input;
        cin >> input;

        // Check if the input is exactly one character
        if (input.length() != 1) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter only one character!" << endl;
            continue; // Skip the rest of the loop and prompt again
        }

        char choice = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

        // Input validation for choice
        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' ||
            (choice == 'A' && salarySelected) || 
            (choice == 'B' && businessSelected) || 
            (choice == 'C' && dividendSelected)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid option or already selected. Please try again." << endl;
            continue; // Skip the rest of the loop and prompt again
        }

        // Prevent choosing options D or E if no income data has been entered
        if ((choice == 'D' || choice == 'E') && 
            !salarySelected && !businessSelected && !dividendSelected) {
            cout << "Please enter at least one income source before calculating or editing." << endl;
            continue;
        }

        cin.ignore(); // Ignore the newline character left by cin >> input

        switch (choice) {
            case 'A': {
                cout << "Enter your company name: ";
                getline(cin, income.companyName);
                income.position = getValidString("Enter your position (staff, management, director, etc...): ");
                cout << "Enter your monthly salary amount in RM: ";
                income.salary = getValidAmount();
                salarySelected = true;
                cout << "Salary information added successfully!" << endl;
                break;
            }
            case 'B': {
                income.businessType = getValidString("\nEnter your business type and description (Goods & Services, etc...): ");
                cout << "Enter your business income amount for the financial year in RM: ";
                income.businessIncome = getValidAmount();
                businessSelected = true;
                cout << "Business information added successfully!" << endl;
                break;
            }
            case 'C': {
                cout << "\nEnter your dividend amount for the financial year in RM: ";
                income.dividend = getValidAmount();
                dividendSelected = true;
                cout << "Dividend information added successfully!" << endl;
                break;
            }
            case 'D': {
                printBill(income);
                return; // Exit the function after calculating incomes
            }
            case 'E': {
                editInformation(income, salarySelected, businessSelected, dividendSelected);
                break;
            }
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

//Getter function to use in other cpp files
double getTotalIncome()
{    
    CalcTotalIncome(income.annualSalary(income.salary), income.businessIncome, income.dividend);
    return CalcTotalIncome(income.annualSalary(income.salary), income.businessIncome, income.dividend);
}

