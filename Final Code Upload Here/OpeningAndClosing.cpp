/* 
1)  Programmer      : MAHAVIGNA JYOTHI ESWERA A/L K MURTHY
    USM email       : mahavigna@student.usm.my
    Github Username : Mahavigna
    Matric No.      : 23301624

Program Function: Contains functions to display welcome page of program, greeting user by name, and displaying a thank you message on the terminal from ThankYou.txt file

 */


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "FormatText.hpp" 
#include "Getting_Details.hpp"



using namespace std;

	
//Function purpose: Display Thank You
void DisplayThankYou() {
    // Open the file
    ifstream inputFile("ThankYou.txt");

    // Check if the file is open
    if (inputFile.is_open()) {
        string line;
        // Read and display each line of the file
        while (getline(inputFile, line)) {
            cout << "\033[1;36m"; // Cyan color
            cout << line << endl;
            cout << "\033[0m"; // Reset color
        }
        // Close the file
        inputFile.close();
    } else {
        // If the file couldn't be opened, display an error message
        cerr << "Unable to open file ThankYou.txt" << endl;
    }
}

//Function purpose: Display Welcome
void WelcomeMsg() {
    // Display ASCII art
    string asciiArt = R"(
 __       __            __                                                    ________                   \
/  |  _  /  |          /  |                                                  /        |                  \
$$ | / \ $$ |  ______  $$ |  _______   ______   _____  ____    ______        $$$$$$$$/   ______          \
$$ |/$  \$$ | /      \ $$ | /       | /      \ /     \/    \  /      \          $$ |    /      \         \
$$ /$$$  $$ |/$$$$$$  |$$ |/$$$$$$$/ /$$$$$$  |$$$$$$ $$$$  |/$$$$$$  |         $$ |   /$$$$$$  |        \
$$ $$/$$ $$ |$$    $$ |$$ |$$ |      $$ |  $$ |$$ | $$ | $$ |$$    $$ |         $$ |   $$ |  $$ |        \
$$$$/  $$$$ |$$$$$$$$/ $$ |$$ \_____ $$ \__$$ |$$ | $$ | $$ |$$$$$$$$/          $$ |   $$ \__$$ |        \
$$$/    $$$ |$$       |$$ |$$       |$$    $$/ $$ | $$ | $$ |$$       |         $$ |   $$    $$/         \
$______  $$/  $$$$$$$/ $$/  $$$$$$$/  $$$$$$/  $$/  $$/  $$/  $$$$$$$________   $$/     $$$$$$/          \
/      |                                                            /        |                           \
$$$$$$/  _______    _______   ______   _____  ____    ______        $$$$$$$$/   ______   __    __        \
  $$ |  /       \  /       | /      \ /     \/    \  /      \          $$ |    /      \ /  \  /  |       \
  $$ |  $$$$$$$  |/$$$$$$$/ /$$$$$$  |$$$$$$ $$$$  |/$$$$$$  |         $$ |    $$$$$$  |$$  \/$$/        \
  $$ |  $$ |  $$ |$$ |      $$ |  $$ |$$ | $$ | $$ |$$    $$ |         $$ |    /    $$ | $$  $$<         \
 _$$ |_ $$ |  $$ |$$ \_____ $$ \__$$ |$$ | $$ | $$ |$$$$$$$$/          $$ |   /$$$$$$$ | /$$$$  \        \
/ $$   |$$ |  $$ |$$       |$$    $$/ $$ | $$ | $$ |$$       |         $$ |   $$    $$ |/$$/ $$  |       \
$$______$$/   $$/  $$__$$$/  $$$$$$/  $$/  $$__ $$/  $$$$$$$/__        $$/     $$$$$$$/ $$/   $$/        \
 /      \           /  |                    /  |            /  |                                         \
/$$$$$$  |  ______  $$ |  _______  __    __ $$ |  ______   _$$ |_     ______    ______                   \
$$ |  $$/  /      \ $$ | /       |/  |  /  |$$ | /      \ / $$   |   /      \  /      \                  \
$$ |       $$$$$$  |$$ |/$$$$$$$/ $$ |  $$ |$$ | $$$$$$  |$$$$$$/   /$$$$$$  |/$$$$$$  |                 \
$$ |   __  /    $$ |$$ |$$ |      $$ |  $$ |$$ | /    $$ |  $$ | __ $$ |  $$ |$$ |  $$/                  \
$$ \__/  |/$$$$$$$ |$$ |$$ \_____ $$ \__$$ |$$ |/$$$$$$$ |  $$ |/  |$$ \__$$ |$$ |                       \
$$    $$/ $$    $$ |$$ |$$       |$$    $$/ $$ |$$    $$ |  $$  $$/ $$    $$/ $$ |                       \
 $$$$$$/   $$$$$$$/  $$/  $$$$$$$/  $$$$$$/  $$/  $$$$$$$/    $$$$/   $$$$$$/  $$/                       \
)";


    // Display the ASCII art
    cout << "\033[1;36m"; // Cyan color
    std::cout << asciiArt << std::endl;
    cout << "\033[0m"; // Reset color

    int linelength = 83;
    // Disclaimer
    printLine('=', linelength);
    cout << "\033[1;33m"; // Yellow color
    cout << centerText("Disclaimer:", 80) << endl;
    cout << "\033[0m"; // Reset color
    cout << centerText("This is an INDIVIDUAL income tax calculator that does not support joint assessment.", 80) << endl;
    cout << centerText("Please answer honestly as the program relies on your input.", 80) << endl;
    printLine('=', linelength);

}

void UserNameWelcome(const string& name){
    // Display the welcome message with login time
    time_t now = time(0);
    std::string loginTime = ctime(&now); // Get the current time as a string

    // Remove the newline character from the login time
    loginTime.erase(loginTime.find_last_not_of('\n') + 1);

    int tableWidth = 83; // Total width of the table

    // Construct the welcome message
    std::string welcomeMessage = "Welcome, " + TaxPayer.name + "!";
    std::string loginMessage = "Login Time: " + loginTime;

    // Center the welcome message and login time
    std::string centeredWelcome = centerText(welcomeMessage, tableWidth - 2); // Subtract 2 for borders
    std::string centeredLogin = centerText(loginMessage, tableWidth - 2); // Subtract 2 for borders

    // Print the top border of the table
    printLine('=', tableWidth);

    // Print the centered welcome message
    std::cout << "|" << centeredWelcome << " |" << std::endl;

    // Print the centered login time
    std::cout << "|" << centeredLogin << "|" << std::endl;

    // Print the bottom border of the table
    printLine('=', tableWidth);
}
