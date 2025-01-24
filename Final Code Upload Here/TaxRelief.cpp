/*
1)  Programmer     : OOI YEEZON
    USM Email      : yeezon@student.usm.my
    GitHub Username: yeezon1
    Matric No.     : 23301291

2)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Purpose: Allow user to choose expenses by category and whether applicable. 
                 List the expenses for purpose of tax relief. 
                 Simplify calculation of relief to simple questions.
*/

// Header Files containing relevant functions and libraries
#include "TaxRelief.hpp"
#include "FormatText.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

double total_deductible = 0.0; // Initialize global variable to store total deductible

// Maximum deductions for each expense category
const double MaxDeductions[23] = {
    9000,  // 1. Individual and dependent relatives
    8000,  // 2. Expenses for parents (medical, dental, etc.)
    6000,  // 3. Purchase of basic supporting equipment for disabled
    6000,  // 4. Disabled individual
    7000,  // 5. Education fees (self)
    10000, // 6. Medical expenses (serious diseases, fertility, etc.)
    1000,  // 7. Expenses (medical examination, COVID-19, mental health)
    4000,  // 8. Expenses for child (intellectual disability, early intervention)
    2500,  // 9. Lifestyle (books, computers, internet, courses)
    1000,  // 10. Lifestyle (sports equipment, gym membership)
    1000,  // 11. Breastfeeding equipment
    3000,  // 12. Child care fees
    8000,  // 13. Skim Simpanan Pendidikan Nasional
    4000,  // 14. Husband/wife/alimony
    5000,  // 15. Disabled husband/wife
    2000,  // 16. Unmarried child under 18
    2000,  // 17. Unmarried child 18+ (A-Level, diploma, etc.)
    6000,  // 18. Disabled child
    7000,  // 19. Life insurance and EPF
    3000,  // 20. Deferred Annuity and PRS
    3000,  // 21. Education and medical insurance
    350,   // 22. SOCSO contribution
    2500  // 23. Electric vehicle charging facilities
};

// Array of category descriptions
const string categories[23] = {
    "Individual and dependent relatives",
    "Expenses for parents (medical, dental, etc.)",
    "Purchase of basic supporting equipment for disabled family member",
    "As a disabled individual",
    "Education fees (self)",
    "Medical expenses (serious diseases, fertility, etc.)",
    "Expenses (medical examination, COVID-19, mental health)",
    "Expenses for child (intellectual disability, early intervention)",
    "Lifestyle (books, computers, internet, courses)",
    "Lifestyle (sports equipment, gym membership)",
    "Breastfeeding equipment",
    "Child care fees",
    "Skim Simpanan Pendidikan Nasional",
    "Husband/Wife/alimony payment",
    "Disabled Husband/Wife",
    "Unmarried child under 18",
    "Unmarried child 18+ (A-Level, diploma, etc.)",
    "Disabled child",
    "Life insurance and EPF",
    "Deferred annuity or PRS",
    "Education or medical insurance",
    "SOCSO contributions",
    "Electric vehicle charging facilities"
};

// Function prototypes
void selectionexpenses();
void AskQuestionForSingle(double dexpenses[]);
void AskQuestionForMarried(double dexpenses[], char maritalstatus);
double calculateTotalDeductible(double dexpenses[], int size);
void displayDeductibleTable(double dexpenses[]);
void PrintTable(double dexpenses[]);
double getTotalRelief();
bool askQuestion(const string& question);
double getNumberInput(const string& prompt);

// Function to handle the selection of expenses
void selectionexpenses()
{
    double dexpenses[23] = {0.00}; // Initialize all deductible expenses to 0

    // Display the allowed categories for expenses
    cout << "\n================================================================================================\n";
    cout << "                                 <Part 3. Relief Selection>\n";
    cout << "================================================================================================\n";
    cout << "The following list is the allowed categories for expenses:\n";
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";
    cout << "| No | Category                                                          | Maximum Deduction   |\n";
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";
    for (int i = 0; i < 23; i++)
    {
        cout << "| " << setw(2) << i + 1 << " | " << left << setw(65) << setfill(' ')
             << categories[i] // Use the array for category descriptions
             << " | RM " << setw(16) << right << MaxDeductions[i] << " |\n";
    }
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";
    
    cout <<"\n" <<endl;

    // Ask for marital status
    char maritalstatus;
    while (true){
        cout << "\nPlease select your marital status:\n";
        cout << "S. Single\n";
        cout << "M. Married\n";
        cout << "D. Divorced\n";
        cout << "Enter your choice (S, M or D): ";
        string input; // Use a string to read the entire line
        getline(cin, input); // Read the entire line
        for (char &ch : input) {
        ch = toupper(ch);
        }

        // Check if the input is a single character and is either 'S', 'M', or 'D'
        if (input.length() == 1 && (input[0] == 'S' || input[0] == 'M' || input[0] == 'D'))
        {
            maritalstatus = input[0]; // Assign the valid character to maritalstatus
            break; // Exit the loop
        }
        cout << "Invalid input!!! Please enter only a single character (S, M or D).\n";
    }

    // Handle expenses based on marital status
    if (maritalstatus == 'S')
    {
        AskQuestionForSingle(dexpenses);
    }
    else
    {
        AskQuestionForMarried(dexpenses, maritalstatus);
    }

    // Display the deductible amounts in a table
    displayDeductibleTable(dexpenses);
}

// Function to handle questions for single individuals
void AskQuestionForSingle(double dexpenses[])
{
    int categoriesForSingle[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 18, 19, 20, 21, 22}; // Categories for single
    
    for (int i : categoriesForSingle)
    {
        string category = categories[i]; // Get category description from the array

        if (askQuestion("Do you have any expenses for " + category + "?"))
        {
            double expenses = getNumberInput("Enter the amount you spent on " + category + " (RM): ");
            dexpenses[i] = min(expenses, MaxDeductions[i]);
            cout << fixed << setprecision(2);
            cout << "Your deductible amount for " << category << " is RM " << dexpenses[i] << ".\n";
        }
        else
        {
            cout << "No expenses claimed for " << category << ".\n";
        }
    }
}

// Function to handle questions for married individuals
void AskQuestionForMarried(double dexpenses[], char maritalstatus)
{
    // Ask if the user has any children
    bool hasChildren = askQuestion("Do you have any children?");

    for (int i = 0; i < 23; i++)
    {
        // Skip child-related categories if the user has no children
        if (!hasChildren && (i == 7 || i == 11 || i == 15 || i == 16 || i == 17))
        {
            continue; 
        }

        //Skips Alimony Payment if they are not divorced
        if(i == 13 && maritalstatus != 'D'){
            continue;
        }

        string category = categories[i]; // Get category description from the array

        if (askQuestion("Do you have expenses for " + category + "?"))
        {
            if (i == 15 || i == 16) // Categories depending on the number of children
            {
                double numChildren = getNumberInput("Enter the number of " + category + ": ");
                dexpenses[i] = numChildren * 2000;
            }
            else if (i == 17) // Categories depending on the number of children
            {
                double numChildren = getNumberInput("Enter the number of " + category + ": ");
                dexpenses[i] = numChildren * 6000;
            }
            else
            {
                double expenses = getNumberInput("Please enter your expenses for " + category + " (RM): ");
                dexpenses[i] = min(expenses, MaxDeductions[i]);
            }
            cout << fixed << setprecision(2);
            cout << "Deductible amount: RM " << dexpenses[i] << ".\n";
        }
        else
        {
            cout << "You do not have expenses for " << category << ".\n";
        }
    }
}

// Function to calculate total deductible
double calculateTotalDeductible(double dexpenses[], int size)
{
    double total = 0.0;

    for (int i = 0; i < size; i++)
    {
        total += dexpenses[i];
    }
    return total;
}

// Function to display the deductible amounts in a table
void displayDeductibleTable(double dexpenses[])
{
    // Calculate and update the total deductible
    total_deductible = calculateTotalDeductible(dexpenses, 23);

    cout << "\n================================================================================================\n";
    cout << "                                  <Deductible Amounts>\n";
    cout << "================================================================================================\n";
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";
    cout << "| No | Category                                                          | Deductible Amount   |\n";
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";
    for (int i = 0; i < 23; i++)
    {
        if (dexpenses[i] > 0)
        {
            cout << "| " << setw(2) << i + 1 << " | " << left << setw(65) << setfill(' ')
                 << categories[i] // Use the array for category descriptions
                 << " | RM " << setw(16) << right << dexpenses[i] << " |\n";
        }
    }
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";
    cout << "       Total deductible amount for all categories                          RM ";
    cout << setw(16) << right << total_deductible << "\n";
    cout << "+----+-------------------------------------------------------------------+---------------------+\n";

    PrintTable(dexpenses);
}

void PrintTable(double dexpenses[])
{
    ofstream outFile("Relief_Summary.txt");
    if (!outFile.is_open()) {
        cerr << "\nError: Unable to open file for writing!" << endl;
        return;
    }    
    // Calculate and display the total deductible
    total_deductible = calculateTotalDeductible(dexpenses, 23);

    outFile << "\n================================================================================================\n";
    outFile << "                                     DEDUCTIBLE AMOUNTS\n";
    outFile << "================================================================================================\n";
    outFile << "+----+-------------------------------------------------------------------+---------------------+\n";
    outFile << "| No | Category                                                          | Deductible Amount   |\n";
    outFile << "+----+-------------------------------------------------------------------+---------------------+\n";
    for (int i = 0; i < 23; i++)
    {
        if (dexpenses[i] > 0)
        {
            outFile << "| " << setw(2) << i + 1 << " | " << left << setw(65) << setfill(' ')
                 << categories[i] // Use the array for category descriptions
                 << " | RM " << setw(16) << right << dexpenses[i] << " |\n";
        }
    }
    outFile << "+----+-------------------------------------------------------------------+---------------------+\n";
    outFile << "       Total deductible amount for all categories                          RM ";
    outFile << setw(16) << right << total_deductible << "\n";
    outFile << "+----+-------------------------------------------------------------------+---------------------+\n";

    cout << "\nTax relief summary written to Relief_Summary.txt successfully!" << endl;
}

// Gets total reliefs to be used in tax calculation
double getTotalRelief()
{
    return total_deductible; // Return the updated global variable
}
