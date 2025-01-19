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

// Function to calculate pilgrimage rebate
double calculatePilgrimageRebate() {
    double rebate = 0.0;

    if (user.NoTime <= 2) {
        if (Travel.travelled == 'Y') {
            // Loop for cabin class input validation
            while (true) {
                cout << "g) Cabin Class (Economy = E | Other = O): ";
                cin >> Travel.cabin;
                Travel.cabin = toupper(Travel.cabin);
                if (Travel.cabin == 'E' || Travel.cabin == 'O') {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid input! Please enter 'E' for Economy or 'O' for Other." << endl;
                }
            }

            if (Travel.destination == 'A') {
                switch(Travel.cabin) {
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
                switch(Travel.cabin) {
                    case 'E':
                        cout << "Tax Rebate of RM 20." << endl;                    
                        rebate = 20;
                        break;
                    case 'O': 
                        cout << "Tax Rebate of RM 150." << endl;
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
    double ChargableIncome = TotalIncome - TotalReliefs;

    cout << "Your Chargeable income is: RM " << ChargableIncome << endl;

    // RM 400 rebate for chargeable income below RM 35,000
    double rebate = 0.0;
    if (ChargableIncome < 35000 && ChargableIncome >= 0) {
        cout << "You are entitled to a RM 400 tax rebate" << endl;
        rebate = 400;
    }

    // Loop for religion input validation
    while (true) {
        cout << "\na) Please enter your religion (I = Islam | O = Other): ";
        cin >> user.religion;
        user.religion = toupper(user.religion);
        if (user.religion == 'I' || user.religion == 'O') {
            break;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input! Please enter 'I' for Islam or 'O' for Other." << endl;
        }
    }

    // Zakat/Fitrah payment for Muslims
    if (user.religion == 'I') {
        cout << "\nb) Please enter your Zakat/Fitrah payment for this year : RM  ";
        user.zakat = getValidAmount();
    } else {
        cout <<"\nb) Not Eligible for Zakat/Fitrah tax rebate.\n";
        user.zakat = 0;
    }

    

    // Loop for pilgrimage input validation
    while (true) {
        cout << "\nc) Have you made a religious pilgrimage before? (Y / N): ";
        cin >> user.pilgramage;
        user.pilgramage = toupper(user.pilgramage);        
        if (user.pilgramage == 'Y' || user.pilgramage == 'N') {
            break;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
        }
    }

    if (user.pilgramage == 'Y') {
        cout << "\nd) How many times in your life? : ";
        user.NoTime = getValidAmount();

        if (user.NoTime <= 2) {
            // Loop for travelled input validation
            while (true) {
                cout << "\ne) Did you make a pilgrimage this year? (Y / N): ";
                cin >> Travel.travelled;
                Travel.travelled = toupper(Travel.travelled);
                if (Travel.travelled == 'Y' || Travel.travelled == 'N') {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
                }
            }

            if (Travel.travelled == 'Y') {
                // Loop for destination input validation
                while (true) {
                    cout << "\nf) Destination (A = ASEAN Region | O = Outside ASEAN): ";
                    cin >> Travel.destination;
                    Travel.destination = toupper(Travel.destination);
                    if (Travel.destination == 'A' || Travel.destination == 'O') {
                        break;
                    } else {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "Invalid input! Please enter 'A' for ASEAN or 'O' for Outside ASEAN." << endl;
                    }
                }

                rebate += calculatePilgrimageRebate();
            }
        }
    }

    return rebate + user.zakat;
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

void FinalTax() {

    // Calculate total income and reliefs
    double TotalIncome = getTotalIncome();
    double TotalReliefs = getTotalRelief();
    double ChargableIncome = TotalIncome - TotalReliefs;

    // Calculate tax
    double tax = calculateTax(ChargableIncome);

    // Calculate rebates (zakat + pilgrimage)
    double rebate = Rebate();
    user.rebate = rebate;

    // Apply rebates to tax
    user.finaltax = user.tax - user.rebate;
    if (user.finaltax < 0) {
        user.finaltax = 0; // Tax cannot be negative
    }

    // Display the final tax payable
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "\n- Your Income Tax before Rebate is RM " << user.tax << endl;
    cout << "-Your total Tax Rebate is RM " << user.rebate << endl;
    cout << "-Your Final Tax payable after Rebate is: RM " << user.finaltax << endl;

}