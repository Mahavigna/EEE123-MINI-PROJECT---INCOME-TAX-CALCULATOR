//Programmer : Syuhaida Balqis Binti Mohammad Shariman
//USM email : syublqs@student.usm.my
//GitHub username : syublqs
//Matric No.: 23300650


#include <iostream>
#include <iomanip>
#include "main.hpp"
using namespace std;

int main() {
    double salary = 0.0, business = 0.0, dividend = 0.0;
    int choice;

    cout << "Let's proceed to the income selection" << endl;

    do {
        cout << "\nChoose your Income:\n";
        cout << "1. Salary\n";
        cout << "2. Business\n";
        cout << "3. Dividend\n";
        cout << "4. Finish and calculate total\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (salary == 0) {
                    cout << "Enter your salary in RM: ";
                    cin >> salary;
                } else {
                    cout << "You have already entered your salary.";
                }
                break;

            case 2:
                if (business == 0) {
                    cout << "Enter your business income in RM: ";
                    cin >> business;
                } else {
                    cout << "You have already entered your business income.";
                }
                break;

            case 3:
                if (dividend == 0) {
                    cout << "Enter your dividend income in RM: ";
                    cin >> dividend;
                } else {
                    cout << "You have already entered your dividend income.";
                }
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice. Please try again.";
        }
    } while (choice != 4);

    
    cout << "\n=====================================\n";
    cout << "|            INCOME DETAILS        |\n";
    cout << "=====================================\n";
    cout << "| Description       | Amount (RM)   |\n";
    cout << "=====================================\n";
    cout << "| Salary           | " << setw(13) << right << fixed << setprecision(2) << salary << " |\n";
    cout << "| Business Income  | " << setw(13) << right << fixed << setprecision(2) << business << " |\n";
    cout << "| Dividend Income  | " << setw(13) << right << fixed << setprecision(2) << dividend << " |\n";
    cout << "=====================================\n";

    double totalIncome = salary + business + dividend;

    cout << "| Total Income     | " << setw(13) << right << fixed << setprecision(2) << totalIncome << " |\n";
    cout << "=====================================\n";

    return 0;
}

