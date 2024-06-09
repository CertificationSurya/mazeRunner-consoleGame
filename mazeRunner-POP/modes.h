#pragma once

#include "fundamentals.h"
#include "helper.h"
// #include "display.h"
#include "maze.h"

void timer() {
    int timeLimit = 30; // Time limit in seconds

    // Timer logic
    std::time_t start_time = std::time(nullptr); // Get current time
    std::time_t current_time;
    std::time_t end_time = start_time + timelimit;

    while (true) {

        // Check the time
        current_time = time(nullptr);
        if (current_time >= end_time) {
            // clearing the screen and showing Time's up!
            clearScreen();
            cout << "\nTime's up! Game Over.\n";
            cout << "You reached " << level << " level \n";
            break;
        }
        gotoxy(1, 1);
        // Display time remaining to the player
        cout << "Time remaining: " << end_time - current_time << " seconds";

        // this_thread::sleep_for(chrono::seconds(1));
    }
}
void movePlayerwithtimer(int x, int y, char c) {
    int timeLimit = 30; // Time limit in seconds

    // Timer logic
    std::time_t start_time = std::time(nullptr); // Get current time
    std::time_t current_time;
    std::time_t end_time = start_time + timelimit;

    while (true)  {
        current_time = time(nullptr);
        if (current_time >= end_time) {
            // clearing the screen and showing Time's up!
            clearScreen();
            Sleep(1000);
            cout << "\nTime's up! Game Over.\n";
            cout << "your reached level " << level << " before demise";

			cout << "\n";
		
			level = 1;
			mazeRows = 8;
			mazeCols = 14;
			cout << "Press any key continue.";
			_getch();
			throw runtime_error("BreakException");
            // exit(0);
        }
        gotoxy(2, 4);
        // Display time remaining to the player
        cout << "Time remaining: " << end_time - current_time << " seconds";

        // this_thread::sleep_for(chrono::seconds(1));

        gotoxy(x, y);
        std::cout << c;

        if (_kbhit())
        {
            char key = _getch();
            gotoxy(x, y);
            std::cout << ' '; // Clear previous position

            int prevX = x;
            int prevY = y;

            // Move the player based on arrow key input

            switch (key) {
                case 72: // Up Arrow key code
                case 119: // w
                    prevY = y;
                    y--;
                    break;
                case 80: // Down Arrow key code
                case 115: // s
                    prevY = y;
                    y++;
                    break;
                case 75: // Left Arrow key code
                case 97: // a
                    prevX = x;
                    x--;
                    break;
                case 77: // Right Arrow key code
                case 100: // d
                    prevX = x;
                    x++;
                    break;
                case 27: // ESCAPE key
                    clearScreen();
                    throw std::runtime_error("BreakException");
                break;
            default:
                break;
            }
            // Check for collisions with walls or obstacles
            if ((
                    (getASCIIAtPosition(x, y) == -37) || // giving -37 for solid block as ascii value
                    (getCharacterAtPosition(x, y) == '|') ||
                    (getCharacterAtPosition(x, y) == '*') ||
                    (getCharacterAtPosition(x,y) == 'S')
                    ))
            {
                x = prevX;
                y = prevY;
            }

            // condition to check whether the player has reached out of the maze or not.
            if (getCharacterAtPosition(x, y) == 'E')
            {
                clearScreen();
                cout << "Congratulations! You have won the game." << endl;
                cout << "Now proceed to the next level." << endl;
                Sleep(400);

                break;
            } // now display  a portal at the final destination.
        }
    }
    timelimit += 15;
}

void movePlayer(int x, int y, char c)
{
    // changeSystemColor();
    // enableBGText(BACKGROUND_SILVER);

    // Character representing the player
    while (true)
    {
        gotoxy(x, y);
        std::cout << c;
        // using the _kbhit to detect which key is being hit by hte uer.
        if (_kbhit())
        {
            char key = _getch();
            gotoxy(x, y);
            std::cout << ' ';
            // Clear previous position

            int prevX = x;

            // Move the player based on arrow key input
            int prevY = y;
            switch (key)
            {
            case 72: // Up Arrow key code
                prevY = y;
                y--;
                break;
            case 80: // Down Arrow key code
                prevY = y;
                y++;
                break;
            case 75: // Left Arrow key code
                prevX = x;
                x--;
                break;
            case 77: // Right Arrow key code
                prevX = x;
                x++;
                break;
            case 27: // ESCAPE key
                clearScreen();
                throw std::runtime_error("BreakException");
                // goto StartOfGame;
                break;
            default:
                break;
            }

            if (
                (getASCIIAtPosition(x, y) == -37) || // getting -37 for solid block as ascii value
                (getCharacterAtPosition(x, y) == 'S'))
            {
                x = prevX;
                y = prevY;
            }

            

            // condition to check whether the player has reached out of the maze or not.
            if (getCharacterAtPosition(x, y) == 'E')
            {
                clearScreen();
                cout << "Congratulations! You have won the game." << endl;
                cout << "Now proceed to the next level." << endl;
                Sleep(400);

                break;
            } // now display  a portal at the final destination.
        }
    }
}

void classic()
{
    // changeSystemColor();

    clearScreen();
    loadingbar();
    clearScreen();
    centerText("WELCOME TO THE CLASSIC MODE OF THIS GAME.");
    cout << endl;
    centerText("+=========================================================================+ \n");
    centerText("|| \n");
    centerText("In this mode, you have to survive as long as you can. \n");
    centerText("The Rules For this mode are Below : \n");
    centerText("-> Complete the maze within the given time frame \n");
    centerText("|| \n");
    centerText("+=========================================================================+ \n");
    Sleep(2000);
    clearScreen();
    // asking the user to enter the character with which he wants to play the game.
    cout << "+=================================+\n";
    cout << "|                                 |\n";
    cout << "| enter your character :          |\n";
    cout << "|                                 |\n";
    cout << "+=================================+\n";
    superman.player = _getch();
    clearScreen();
    // maiking the use of the system cls to create an illusion that character is entered within the box.
    cout << "+=================================+\n";
    cout << "|                                 |\n";
    cout << "| enter your character : " << superman.player << "        |\n";
    cout << "|                                 |\n";
    cout << "+=================================+\n";

    Sleep(1000);
    while (true) {
        // clearing the screen every time the playerr wins the game.
        clearScreen();
        Sleep(900);
        gotoxy(0, 0);

        // moving the cursor on the top to display the score on the right top most corner of the console.

        vector<vector<char>> maze = generateMaze(mazeRows, mazeCols);
        gotoxy(1, 4);
        displayMaze(maze);
        // displayDialogueBox();
        // movePlayer(superman.x, superman.y, superman.player);
        movePlayerwithtimer(superman.x, superman.y, superman.player);
        // incresing the score by 20 when the user clears a maze.
        // score += 20;
        // updatintg the size of the maze every time the user survives the game.
        mazeRows += 1;
        mazeCols += 2;
    }
}
