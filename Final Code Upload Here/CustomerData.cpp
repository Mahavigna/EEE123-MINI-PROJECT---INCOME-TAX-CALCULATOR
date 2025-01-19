/*

1)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: Prints User / Tax Payers data from all the sections into one reciept for easy filling and reference.
*/

#include "main.hpp"
#include "Income.hpp"
#include "TaxRelief.hpp"
#include "Login_Register.hpp"
#include "CalcTotalTax.hpp"
#include "Getting_Details.hpp"

// Function to print a line of a specific symbol
void PrintFileLine(char symbol, int length, ofstream& file) {
    for (int i = 0; i < length; i++) {
        file << symbol;
    }
    file << endl;
}


// Function to convert a string to uppercase
string toUpperCase(const string& text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to print details to a file
void printDetailsToFile(const string& filename) {
    ofstream outputFile(TaxPayer.name + ".txt"); // Open the file for writing

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    int tableWidth = 83; // Width of the relief table

    // Tax Payer Info (Getting_Details.cpp)
    PrintFileLine('=', tableWidth, outputFile);
    outputFile << centerText(toUpperCase("Personal Details"), tableWidth) << endl;
    PrintFileLine('=', tableWidth, outputFile);
    outputFile << "Date:               " << getCurrentDate() << endl;
    outputFile << "Name:               " << TaxPayer.name << endl;
    outputFile << "IC No.:             " << TaxPayer.ic << endl;
    outputFile << "Phone No.:          " << TaxPayer.phoneNo << endl;
    outputFile << "Email:              " << TaxPayer.email << endl;
    outputFile << "TIN:                " << TaxPayer.TIN << endl;
    PrintFileLine('=', tableWidth, outputFile);

    // Tax Payer Income sources (Income.cpp)
    outputFile << endl;
    PrintFileLine('=', tableWidth, outputFile);
    outputFile << centerText(toUpperCase("Income Sources Summary"), tableWidth) << endl;
    PrintFileLine('=', tableWidth, outputFile);

    outputFile << left << setw(20) << "Income" << setw(40) << "Description" << right << setw(15) << "Amount (RM)" << endl;
    PrintFileLine('-', tableWidth, outputFile);

    if (income.salary > 0)
        outputFile << left << setw(20) << "Annual Salary" \
                   << setw(40) << ("From " + income.companyName + " as " + income.position) \
                   << right << setw(15) << fixed << setprecision(2) << income.annualSalary(income.salary) << endl;
    if (income.businessIncome > 0)
        outputFile << left << setw(20) << "Business" \
                   << setw(40) << ("From " + income.businessType) \
                   << right << setw(15) << fixed << setprecision(2) << income.businessIncome << endl;
    if (income.dividend > 0)
        outputFile << left << setw(20) << "Dividend" \
                   << setw(40) << "From investment" \
                   << right << setw(15) << fixed << setprecision(2) << income.dividend << endl;

    PrintFileLine('-', tableWidth, outputFile);
    outputFile << left << setw(60) << "Total Income" << right << setw(15) << fixed << setprecision(2) << CalcTotalIncome(income.salary, income.businessIncome, income.dividend) << endl;
    PrintFileLine('-', tableWidth, outputFile);

    // Insert Relief Summary
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
    PrintFileLine('=', tableWidth, outputFile);
    outputFile << centerText(toUpperCase("Tax Rebate and Final Tax"), tableWidth) << endl;
    PrintFileLine('=', tableWidth, outputFile);

    // Print Tax Calculated and Rebate
    outputFile << fixed << setprecision(2); // Format output to 2 decimal places
    outputFile << "\nYour Income Tax before Rebate is RM " << user.tax << endl;
    outputFile << "\nYour total Tax Rebate is RM " << user.rebate << endl;
    outputFile << "\nYour Final Tax payable after Rebate is: RM " << user.finaltax << endl;

    outputFile.close(); // Close the file
    cout << "\nDetails have been written to " << filename + ".txt" << " successfully!\n";
}