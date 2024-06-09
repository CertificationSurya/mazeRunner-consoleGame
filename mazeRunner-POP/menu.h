#pragma once
#include "fundamentals.h"
#include "helper.h"

using namespace std;

string startMenu() {
    clearScreen();
    cout << setw(100) << "  _______ _____ _____ _     _      _______ _____ _       _ _    _   " << endl;
    cout << setw(97) << "|  |  | |   |   |   |\\    |      |  |  | |     |\\     | |    |" << endl;
    cout << setw(97) << "|  |  | |   |   |   | \\   |      |  |  | |     | \\    | |    |" << endl;
    cout << setw(97) << "|  |  | |___|   |   |  \\  |      |  |  | |____ |   \\  | |    |" << endl;
    cout << setw(97) << "|  |  | |   |   |   |   \\ |      |  |  | |     |    \\ | |    |" << endl;
    cout << setw(97) << "|  |  | |   |   |   |    \\|      |  |  | |     |     \\| |    |" << endl;
    cout << setw(100) << "  |  |  | |   | __|__ |     |      |  |  | |____ |      | |____|   " << endl;
    cout << endl;
    cout << setw(70) << "1. Start " << endl
         << endl;
    cout << setw(71) << "2. Options" << endl
         << endl;
    cout << setw(68) << "3. Quit" << endl
         << endl;
    string mainInput;
    do {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, mainInput);
        if (mainInput == "1") {
            clearScreen();
            return "start";
            break;
        }
        else if (mainInput == "2") {
            clearScreen();
            return "options";
            break;
        }
        else if (mainInput == "3") {
            cout << setw(77) << "Thanks For Playing!!!" << endl;
            exit(0);
        }
        else {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}
string optionsMenu() {
    cout << setw(90) << "_____ _____ _______ _____ _____ _      _ _______ \n";
    cout << setw(90) << "|   | |   |    |      |   |   | |\\     | |      \n";
    cout << setw(90) << "|   | |   |    |      |   |   | | \\    | |      \n";
    cout << setw(90) << "|   | |___]    |      |   |   | |  \\   | |_____ \n";
    cout << setw(90) << "|   | |        |      |   |   | |   \\  |      | \n";
    cout << setw(90) << "|   | |        |      |   |   | |    \\ |      | \n";
    cout << setw(90) << "[___] |        |    __|__ [___] |     \\| _____] \n";

    cout << "\n \n";

    cout << setw(70) << "1. Controls \n" ;
    cout << setw(70) << "2. Credits  \n" ;
    cout << setw(75) << "Press X to go back \n" ;
    string optionsInput;
    do {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, optionsInput);
        if (optionsInput == "1") {
            clearScreen();
            return "controls";
        }
        else if (optionsInput == "2") {
            clearScreen();
            return "credits";
        }
        else if (optionsInput == "X" || optionsInput == "x") {
            clearScreen();
            return "back";
        }
        else {
            cout << setw(73) << "Invalid Input" << endl;
        }
    } while (true);
}

string controlsMenu() {
    cout << setw(100) << "_______ ______ _      _ _______ ______ ______ _       ______ " << endl;
    cout << setw(100) << "|       |    | |\\     |    |    |    | |    | |       |      " << endl;
    cout << setw(100) << "|       |    | | \\    |    |    |    | |    | |       |      " << endl;
    cout << setw(100) << "|       |    | |  \\   |    |    |____| |    | |       |_____ " << endl;
    cout << setw(100) << "|       |    | |   \\  |    |    |\\     |    | |            | " << endl;
    cout << setw(100) << "|       |    | |    \\ |    |    | \\    |    | |            | " << endl;
    cout << setw(100) << "|______ |____| |     \\|    |    |  \\   |____| |______ _____| " << endl;
    cout << endl
         << endl;
    cout << setw(65) << "Action\t\t\tKey \n" ;
    cout << setw(68) << "Move Up   \t\tUp Key \n";
    cout << setw(71) << "Move Down \t\tDown Key \n";
    cout << setw(71) << "Move Left \t\tLeft Key \n";
    cout << setw(73) << "Move Right\t\tRight Key \n";
    cout << endl
         << setw(72) << "Press X to go back \n";
    string input;
    do {
        cout << "\t\t\t\t\t\t\t\t";
        getline(cin, input);
        if (input == "x" || input == "X") {
            clearScreen();
            return "back";
        }
        else {
            cout << setw(73) << "Invalid Input \n";
        }
    } while (true);
}

string creditsMenu() {
    cout << setw(80) << "1. Programmers                  Surya & Sushant        \n";
    cout << setw(80) << "2. Design & Creative Artist     Bikul                  \n";
    cout << setw(65) << "Press X to go back \n\n";

    string input;
    do {
        cout << "\t\t\t\t\t\t\t";
        getline(cin, input);
        if (input == "x" || input == "X") {
            clearScreen();
            return "back";
        }
        else {
            cout << setw(73) << "Invalid Input \n";
        }
    } while (true);
}

void mainMenu() {
    clearScreen();
    loadingScreen();
    string chosenOption;
    do {
        if (startMenu() == "start")  {
            break;
        }
        else  {
            do {
                chosenOption = optionsMenu();
                if (chosenOption == "controls") {
                    if (controlsMenu() == "back")
                        continue;
                }
                else if (chosenOption == "credits") {
                    if (creditsMenu() == "back")
                        continue;
                }
                else if (chosenOption == "back") {
                    chosenOption = "";
                    break;
                }
            } while (true);
            if (chosenOption == "")
                continue;
            else
                break;
        }
    } while (true);
}