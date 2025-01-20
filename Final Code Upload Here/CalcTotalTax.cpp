#include "Income.hpp"
#include "TaxRelief.hpp"
#include "CalcTotalTax.hpp"

using namespace std;


// Class for pilgrimage details
struct Pilgram {
public:
    char travelled;    // Whether the user travelled for pilgrimage
    char destination;  // Destination of pilgrimage (A = ASEAN, O = Outside ASEAN)
    char cabin;        // Cabin class (if applicable)
} Travel;



PayerOfTax user;

// Function to validate input
char getValidatedInput(const string& prompt, const string& errorMsg, const string& validOptions) {
    char input;
    while (true) {
        cout << prompt;
        cin >> input;
        input = toupper(input);
        if (validOptions.find(input) != string::npos) {
            return input;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << errorMsg << endl;
        }
    }
}

// Function to calculate pilgrimage rebate
double calculatePilgrimageRebate(char destination, char cabin) {
    if (destination == 'A') {
        return (cabin == 'E') ? 8.0 : 50.0;
    } else if (destination == 'O') {
        return (cabin == 'E') ? 20.0 : 150.0;
    }
    return 0.0;
}

// Function to calculate total rebates (zakat + pilgrimage)
double calculateTotalRebates() {
    double rebate = 0.0;

    // Religion input
    user.religion = getValidatedInput(
        "\na) Please enter your religion (I = Islam | O = Other): ",
        "Invalid input! Please enter 'I' for Islam or 'O' for Other.",
        "IO"
    );

    // Zakat calculation
    if (user.religion == 'I') {
        cout << "\nb) Please enter your Zakat/Fitrah payment for this year: RM ";
        user.zakat = getValidAmount();
    } else {
        cout << "\nb) Not eligible for Zakat/Fitrah tax rebate.\n";
        user.zakat = 0.0;
    }

    // Pilgrimage input
    user.pilgramage = getValidatedInput(
        "\nc) Have you made a religious pilgrimage before? (Y / N): ",
        "Invalid input! Please enter 'Y' for Yes or 'N' for No.",
        "YN"
    );

    if (user.pilgramage == 'Y') {
        cout << "\nd) How many times in your life? : ";
        user.NoTime = getValidAmount();

        if (user.NoTime <= 2) {
            Travel.travelled = getValidatedInput(
                "\ne) Did you make a pilgrimage this year? (Y / N): ",
                "Invalid input! Please enter 'Y' for Yes or 'N' for No.",
                "YN"
            );

            if (Travel.travelled == 'Y') {
                Travel.destination = getValidatedInput(
                    "\nf) Destination (A = ASEAN Region | O = Outside ASEAN): ",
                    "Invalid input! Please enter 'A' for ASEAN or 'O' for Outside ASEAN.",
                    "AO"
                );

                Travel.cabin = getValidatedInput(
                    "g) Cabin Class (Economy = E | Other = O): ",
                    "Invalid input! Please enter 'E' for Economy or 'O' for Other.",
                    "EO"
                );

                rebate += calculatePilgrimageRebate(Travel.destination, Travel.cabin);
            }
        }
    }

    // Add Zakat to rebate
    return rebate + user.zakat;
}

// Function to calculate tax based on chargeable income
double calculateTax(double chargeableIncome) {
    double tax = 0.0;

    if (chargeableIncome <= 5000) {
        tax = 0;
    } else if (chargeableIncome <= 20000) {
        tax = (chargeableIncome - 5000) * 0.01;
    } else if (chargeableIncome <= 35000) {
        tax = 150 + (chargeableIncome - 20000) * 0.03;
    } else if (chargeableIncome <= 50000) {
        tax = 600 + (chargeableIncome - 35000) * 0.06;
    } else if (chargeableIncome <= 70000) {
        tax = 1500 + (chargeableIncome - 50000) * 0.11;
    } else if (chargeableIncome <= 100000) {
        tax = 3700 + (chargeableIncome - 70000) * 0.19;
    } else if (chargeableIncome <= 400000) {
        tax = 9400 + (chargeableIncome - 100000) * 0.25;
    } else if (chargeableIncome <= 600000) {
        tax = 84400 + (chargeableIncome - 400000) * 0.26;
    } else if (chargeableIncome <= 2000000) {
        tax = 136400 + (chargeableIncome - 600000) * 0.28;
    } else {
        tax = 528400 + (chargeableIncome - 2000000) * 0.30;
    }

    user.tax = tax;
    return user.tax;
}

void displayFinalTax() {
    // Calculate total income and reliefs
    double TotalIncome = getTotalIncome();
    double TotalReliefs = getTotalRelief();
    double ChargeableIncome = max(0.0, TotalIncome - TotalReliefs);

    // Calculate tax
    double tax = calculateTax(ChargeableIncome);

    // Calculate rebates (zakat + pilgrimage)
    double rebate = calculateTotalRebates();
    user.rebate = rebate;

    // Apply rebates to tax
    user.finaltax = max(0.0, user.tax - user.rebate);

    // Display the final tax payable
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << left << setw(40) << "- Your Income Tax before Rebate is:" << "RM " << user.tax << endl;
    cout << left << setw(40) << "- Your Total Tax Rebate is:" << "RM " << user.rebate << endl;
    cout << left << setw(40) << "- Your Final Tax Payable is:" << "RM " << user.finaltax << endl;
}
