/*

1)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: Prints User / Tax Payers data from all the sections into one receipt for easy filling and reference.
*/

//Header Files containing relevant functions and libraries
#include "Income.hpp"
#include "TaxRelief.hpp"
#include "CalcTotalTax.hpp"
#include "Getting_Details.hpp"
#include "FormatText.hpp"



// Function to print details to a file
void printDetailsToFile(const string& filename) {
    ofstream outputFile(TaxPayer.name + ".txt"); // Open the file for writing

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    int tableWidth = 83; // Width of the relief table

    // Tax Payer Info (Getting_Details.cpp)
    formatSectionTitle("Personal Details", tableWidth, outputFile);
    outputFile << "Date:               " << getCurrentDate() << endl;
    outputFile << "Name:               " << TaxPayer.name << endl;
    outputFile << "IC No.:             " << TaxPayer.ic << endl;
    outputFile << "Phone No.:          " << TaxPayer.phoneNo << endl;
    outputFile << "Email:              " << TaxPayer.email << endl;
    outputFile << "TIN:                " << TaxPayer.TIN << endl;
    outputFile << "Religion:           " << user.religion << endl;
    PrintFileLine('=', tableWidth, outputFile);

    // Tax Payer Income sources (Income.cpp)
    outputFile << endl;
    formatSectionTitle("Income Sources Summary", tableWidth, outputFile);

    outputFile << left << setw(20) << "Income" << setw(40) << "Description" << right << setw(15) << "Amount (RM)" << endl;
    PrintFileLine('-', tableWidth, outputFile);

    if (income.salary > 0)
        outputFile << left << setw(20) << "Annual Salary"
                   << setw(40) << ("From " + income.companyName + " as " + income.position)
                   << right << setw(15) << fixed << setprecision(2) << income.annualSalary(income.salary) << endl;
    if (income.businessIncome > 0)
        outputFile << left << setw(20) << "Business"
                   << setw(40) << ("From " + income.businessType)
                   << right << setw(15) << fixed << setprecision(2) << income.businessIncome << endl;
    if (income.dividend > 0)
        outputFile << left << setw(20) << "Dividend"
                   << setw(40) << "From investment"
                   << right << setw(15) << fixed << setprecision(2) << income.dividend << endl;

    PrintFileLine('-', tableWidth, outputFile);
    outputFile << left << setw(60) << "Total Income" << right << setw(15) << fixed << setprecision(2) << CalcTotalIncome(income.salary, income.businessIncome, income.dividend) << endl;
    PrintFileLine('-', tableWidth, outputFile);

    // Reads Relief_Summary.txt file and prints content to this file 
    ifstream reliefFile("Relief_Summary.txt");
    if (reliefFile.is_open()) {
        string line;
        while (getline(reliefFile, line)) {
            outputFile << line << endl;
        }
        reliefFile.close();
    } else {
        cerr << "Error: Unable to open Relief_Summary.txt for reading.\n";
    }

    // Rebate Section Header
    outputFile << endl;
    formatSectionTitle("Tax Rebate and Final Tax", tableWidth, outputFile);

    outputFile << fixed << setprecision(2); // Format output to 2 decimal places
    outputFile << setw(50) << left << "Income Tax before Rebate" << setw(30) << right << user.tax << endl;
    PrintFileLine('-', tableWidth, outputFile);
    outputFile << setw(50) << left << "Total Tax Rebate" << setw(30) << right << user.rebate << endl;
    PrintFileLine('-', tableWidth, outputFile);
    outputFile << setw(50) << left << "Final Tax Payable" << setw(30) << right << user.finaltax << endl;
    PrintFileLine('=', tableWidth, outputFile);

    outputFile.close(); // Close the file
    cout << "\nTax calculation summary written to " << filename << ".txt successfully!" << endl;
}
