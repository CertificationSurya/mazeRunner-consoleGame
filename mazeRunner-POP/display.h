#pragma once

#include "fundamentals.h"
#include "helper.h"
#include "maze.h"

void menuOptions(string arr[], int size, int activeOption) {
	clearScreen();
	// Clear the console (for Windows, use system("clear") for Unix-based systems)
	cout << "\x1b[33m\n\nSelect your choice. \x1b[0m" << endl;
	cout << "+=============================+" << endl;
	for (int i = 0; i < size; i++) {
		if (i == activeOption) {
			cout << BOLD << UNDERLINE << "      " << arr[i] << RESET << endl;
		}
		else {
			cout << "      " << arr[i] << endl;
		}
	}
	cout << "+=============================+" << endl;
}


void displayMaze(const vector<vector<char>> &maze) {
	int i = 0;
	for (const auto &row : maze) {
		gotoxy(mazeStart.x, mazeStart.y + i);
		for (char cell : row) {
			cout << cell << "";
		}
		cout << " " << endl;
		i++;
	}
}
void displayGame(const vector<vector<char>> &maze) {
	displayMaze(maze);
}