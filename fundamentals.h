#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define RESET "\033[0m"


// GLOBAL VARIABLES
int response;
int mazeCols = 14;
int mazeRows = 8;
int score = 0;
int timelimit = 30;
int levelno = 1;
int seconds = 30;
// int dialogueBoxWidth = 40;
// int dialogueBoxHeight = 2 * mazeRows;
string username; // making a global variable to ask for the name of the user.

bool backToMainMenu = false;

char TAB = '\t';
char ESCAPE = 27;

struct Position  {
	int x;
	int y;

	Position(const int &a, const int &b) : x(a), y(b) {}
};
struct Wall {
	pair<int, int> cell1;
	pair<int, int> cell2;
};
struct Player {
	int x;
	int y;
	char player;

	Player(const int &positionX, const int &positionY, const char &playerChar) : x(positionX), y(positionY), player(playerChar){}
};

// Position dialogueBoxStart(90, 5);
Position mazeStart(5, 5);
Player superman(mazeStart.x + 1, mazeStart.y + 1, 'a');