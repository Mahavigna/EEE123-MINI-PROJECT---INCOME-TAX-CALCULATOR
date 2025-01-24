/*
1)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624
*/

//Header Files containing relevant functions and libraries
#include "Income.hpp"
#include "TaxRelief.hpp"
#include "CalcTotalTax.hpp"
#include "FormatText.hpp"
using namespace std;

// Class for pilgrimage details
struct Pilgram {
public:
    char travelled;    // Whether the user travelled for pilgrimage
    char destination;  // Destination of pilgrimage (A = ASEAN, O = Outside ASEAN)
    char cabin;        // Cabin class (if applicable)
} Travel;

PayerOfTax user;
// Function to calculate pilgrimage rebate
double calculatePilgrimageRebate() {
    double rebate = 0.0;

    if (user.NoTime <= 2) {
        if (Travel.travelled == 'Y') {
            // Loop for cabin class input validation
            while (true) {
                cout << "\ng) Cabin Class (Economy = E | Other = O): ";

                // Read the entire input as a string
                string input;
                getline(cin, input);

                // Check if the input is exactly one character
                if (input.length() == 1) {
                    Travel.cabin = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

                    // Validate the choice
                    if (Travel.cabin == 'E' || Travel.cabin == 'O') {
                        break; // Exit the loop if the input is valid
                    } else {
                        // Handle invalid character input
                        cout << "Invalid input! Please enter 'E' for Economy or 'O' for Other.\n";
                    }
                } else {
                    // Handle invalid input (more than one character)
                    cout << "Invalid input. Please enter only one character (E or O).\n";
                }
            }

            if (Travel.destination == 'A') {
                switch (Travel.cabin) {
                    case 'E':
                        cout << "Tax Rebate of RM 8." << endl;
                        rebate = 8;
                        break;
                    case 'O':
                        cout << "Tax Rebate of RM 50." << endl;
                        rebate = 50;
                        break;
                }
            } else if (Travel.destination == 'O') {
                switch (Travel.cabin) {
                    case 'E':
                        cout << "Tax Rebate of RM 20." << endl;
                        rebate = 20;
                        break;
                    case 'O':
                        cout << "\tTax Rebate of RM 150." << endl;
                        rebate = 150;
                        break;
                }
            }
        }
    }

    return rebate;
}

// Function to calculate total rebates (zakat + pilgrimage)
double Rebate() {
    cout << "\n";
    printLine('=', 83);
    cout << setw((83 - 43) / 2) << " " << "< Part 4. Calculation of Total Tax >" << endl;
    printLine('=', 83);

    // Calculate total income and reliefs
    double TotalIncome = getTotalIncome();
    double TotalReliefs = getTotalRelief();
    double ChargeableIncome = TotalIncome - TotalReliefs;

    cout << "Your Chargeable income is: RM " << ChargeableIncome << endl;

    // RM 400 rebate for chargeable income below RM 35,000
    double rebate = 0.0;
    if (ChargeableIncome < 35000 && ChargeableIncome >= 0) {
        cout << "You are entitled to a RM 400 tax rebate" << endl;
        rebate = 400;
    }

    // Loop for religion input validation
    while (true) {
        cout << "a) Please enter your religion (I = Islam | O = Other): ";

        // Read the entire input as a string
        string input;
        getline(cin, input);

        // Check if the input is exactly one character
        if (input.length() == 1) {
            user.religion = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

            // Validate the choice
            if (user.religion == 'I' || user.religion == 'O') {
                break; // Exit the loop if the input is valid
            } else {
                // Handle invalid character input
                cout << "Invalid input! Please enter 'I' for Islam or 'O' for Other.\n";
            }
        } else {
            // Handle invalid input (more than one character)
            cout << "Invalid input. Please enter only one character (I or O).\n";
        }
    }

    // Zakat/Fitrah payment for Muslims
    if (user.religion == 'I') {
        cout << "\nb) Please enter your Zakat/Fitrah payment for this year: RM ";
        user.zakat = getValidAmount();
    } else {
        cout << "\nb) Not Eligible for Zakat/Fitrah tax rebate.\n";
        user.zakat = 0;
    }

    // Loop for pilgrimage input validation
    while (true) {
        cout << "\nc) Have you made a religious pilgrimage before? (Y / N): ";

        // Read the entire input as a string
        string input;
        getline(cin, input);

        // Check if the input is exactly one character
        if (input.length() == 1) {
            user.pilgrimage = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

            // Validate the choice
            if (user.pilgrimage == 'Y' || user.pilgrimage == 'N') {
                break; // Exit the loop if the input is valid
            } else {
                // Handle invalid character input
                cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No.\n";
            }
        } else {
            // Handle invalid input (more than one character)
            cout << "Invalid input. Please enter only one character (Y or N).\n";
        }
    }

    if (user.pilgrimage == 'Y') {
    // Loop for pilgrimage frequency input validation
    while (true) {
        cout << "\nd) How many times in your life? :\n";
        cout << "   A) Less than 2 times\n";
        cout << "   B) Exactly 2 times\n";
        cout << "   C) More than 2 times\n";
        cout << "   Enter your choice (A, B, or C): ";

        // Read the entire input as a string
        string input;
        getline(cin, input);

        // Check if the input is exactly one character
        if (input.length() == 1) {
            char choice = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

            // Validate the choice
            if (choice == 'A' || choice == 'B' || choice == 'C') {
                if (choice == 'A') {
                    user.NoTime = 1; // Less than 2 times
                } else if (choice == 'B') {
                    user.NoTime = 2; // Exactly 2 times
                } else if (choice == 'C') {
                    user.NoTime = 3; // More than 2 times
                }
                break; // Exit the loop if the input is valid
            } else {
                // Handle invalid character input
                cout << "Invalid input! Please enter A, B, or C.\n";
            }
        } else {
            // Handle invalid input (more than one character)
            cout << "Invalid input. Please enter only one character (A, B, or C).\n";
        }
    }

    if (user.NoTime <= 2) {
        // Loop for travelled input validation
        while (true) {
            cout << "\ne) Did you make a pilgrimage this year? (Y / N): ";

            // Read the entire input as a string
            string input;
            getline(cin, input);

            // Check if the input is exactly one character
            if (input.length() == 1) {
                Travel.travelled = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

                // Validate the choice
                if (Travel.travelled == 'Y' || Travel.travelled == 'N') {
                    break; // Exit the loop if the input is valid
                } else {
                    // Handle invalid character input
                    cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No.\n";
                }
            } else {
                // Handle invalid input (more than one character)
                cout << "Invalid input. Please enter only one character (Y or N).\n";
            }
        }

        if (Travel.travelled == 'Y') {
            // Loop for destination input validation
            while (true) {
                cout << "\nf) Destination (A = ASEAN Region | O = Outside ASEAN): ";

                // Read the entire input as a string
                string input;
                getline(cin, input);

                // Check if the input is exactly one character
                if (input.length() == 1) {
                    Travel.destination = toupper(input[0]); // Convert to uppercase for case-insensitive comparison

                    // Validate the choice
                    if (Travel.destination == 'A' || Travel.destination == 'O') {
                        break; // Exit the loop if the input is valid
                    } else {
                        // Handle invalid character input
                        cout << "Invalid input! Please enter 'A' for ASEAN or 'O' for Outside ASEAN.\n";
                    }
                } else {
                    // Handle invalid input (more than one character)
                    cout << "Invalid input. Please enter only one character (A or O).\n";
                }
            }

            rebate += calculatePilgrimageRebate();
            }
        }
    }
    return (rebate + user.zakat);
}

// Function to calculate tax based on chargeable income
double calculateTax(double chargeableIncome) {
    double tax = 0.0;

    if (chargeableIncome <= 5000) {
        // Category A: 0 - 5,000
        tax = 0;
    } else if (chargeableIncome <= 20000) {
        // Category B: 5,001 - 20,000
        tax = (chargeableIncome - 5000) * 0.01;
    } else if (chargeableIncome <= 35000) {
        // Category C: 20,001 - 35,000
        tax = 150 + (chargeableIncome - 20000) * 0.03;
    } else if (chargeableIncome <= 50000) {
        // Category D: 35,001 - 50,000
        tax = 600 + (chargeableIncome - 35000) * 0.06;
    } else if (chargeableIncome <= 70000) {
        // Category E: 50,001 - 70,000
        tax = 1500 + (chargeableIncome - 50000) * 0.11;
    } else if (chargeableIncome <= 100000) {
        // Category F: 70,001 - 100,000
        tax = 3700 + (chargeableIncome - 70000) * 0.19;
    } else if (chargeableIncome <= 400000) {
        // Category G: 100,001 - 400,000
        tax = 9400 + (chargeableIncome - 100000) * 0.25;
    } else if (chargeableIncome <= 600000) {
        // Category H: 400,001 - 600,000
        tax = 84400 + (chargeableIncome - 400000) * 0.26;
    } else if (chargeableIncome <= 2000000) {
        // Category I: 600,001 - 2,000,000
        tax = 136400 + (chargeableIncome - 600000) * 0.28;
    } else {
        // Category J: Exceeding 2,000,000
        tax = 528400 + (chargeableIncome - 2000000) * 0.30;
    }
    user.tax = tax;
    return user.tax;
}

//Displays Final Tax Rebate and Payable Tax amount 
void displayFinalTax() {
    // Display the final tax payablevoid displayFinalTax() {
    // Calculate total income and reliefs
    double TotalIncome = getTotalIncome();
    double TotalReliefs = getTotalRelief();
    double ChargeableIncome = TotalIncome - TotalReliefs;

    // Calculate tax
    double tax = calculateTax(ChargeableIncome);

    // Calculate rebates (zakat + pilgrimage)
    double rebate = Rebate();
    user.rebate = rebate;

    // Apply rebates to tax
    user.finaltax = user.tax - user.rebate;
    if (user.finaltax < 0) {
        user.finaltax = 0; // Tax cannot be negative
    }

    // Display the final tax payable in a table format
    cout << "\n";
    printLine('=', 83); // Print a separator line
    cout << centerText(toUpperCase( "TAX REBATE AND FINAL TAX"), 83) <<endl;
    printLine('=', 83); // Print a separator line
    cout << setw(50) << left << "Tax Details" << setw(30) << right << "Amount (RM)" << endl;
    printLine('-', 83); // Print a separator line

    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << setw(50) << left << "Income Tax before Rebate" << setw(30) << right << user.tax << endl;
    cout << setw(50) << left << "Total Tax Rebate" << setw(30) << right << user.rebate << endl;
    cout << setw(50) << left << "Final Tax Payable" << setw(30) << right << user.finaltax << endl;

    printLine('=', 83); // Print a separator line

}

