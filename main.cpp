#include <iostream>
#include <vector>
#include <conio.h>
#include <utility>
#include <windows.h>
#include <fstream>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define WALL char(219)
#define MAX_LEVEL 5

using namespace std;

// utils func to get map as per level
vector<vector<char>> getMap(int level);

// classes
class Player {
public:
    int column, row;
    char playerLook;
    string username;

    Player(int column, int row, char playerLook, string username) : column(column), row(row), playerLook(playerLook), username(username) {};
    void rePosition(int col, int row)
    {
        this->column = col;
        this->row = row;
    }

    void storeProgress(int level){

    }
};

class Maze {
public:
    vector<vector<char>> mazeCoords;
    pair<int, int> startCoord = {1, 1};
    pair<int, int> endCoord = {8, 7};
    // for maze
    void initializeMaze(int level) {
        mazeCoords = getMap(level);
    }

    void printMaze(const Player &player) {
        for (int i = 0; i < mazeCoords.size(); ++i) {
            for (int j = 0; j < mazeCoords[i].size(); ++j) {
                if (i == player.row && j == player.column) {
                    std::cout << player.playerLook;
                }
                else {
                    std::cout << mazeCoords[i][j];
                }
            }
            std::cout << '\n';
        }
    };
};


// Utilities function
// handle keypress
string handleContinuingPlayer();

bool handleKeyPress(char, Player &, Maze &); // handle movement and check winning.
void clearScreen();

int main() {
    int playerChoice = 1;
    string username;
    while (playerChoice){
        cout<< "Hello stranger are you here for starting a \n" << BOLD << "1. NEW GAME \n" << "2. CONTINUE \n" << RESET;
        cin>> playerChoice;

        if (playerChoice == 1) {
            clearScreen();
            cout<< "Enter Your name, Thrill Seeker: ";
            cin>> username;
            break;
        }
        else if (playerChoice == 2) {
            username = handleContinuingPlayer();
            break;
        }

    }

    int level = 1;
    Maze maze;
    maze.initializeMaze(level);

    cout << "Enter the ascii code for your character: ";
    char playerLook = _getch();
    Player player(maze.startCoord.first, maze.startCoord.second, playerLook, username);




    while (true) {
        maze.printMaze(player);
        char key = _getch();
        bool win = handleKeyPress(key, player, maze);
        if (win) {
            if (level == MAX_LEVEL)  {
                clearScreen();
                cout << BOLD;
                cout << "Congratulation, You Won!";
                cout << RESET;
                Sleep(1500);
                break;
            }
            else {
                cout << BOLD;
                cout << "On to the next level: lv. " << ++level;
                cout << RESET;
                player.rePosition(maze.startCoord.first, maze.startCoord.second);
                maze.initializeMaze(level);
                Sleep(1250);
            }
        }
        clearScreen();
    }

    return 0;
}

// utilities function
bool handleKeyPress(char key, Player &player, Maze &maze) {
    int prevX = player.row;
    int prevY = player.column;

    switch (key) {
    case 72:  // Up Arrow key code
    case 'w': // w
        prevX = player.row;
        player.row--;
        break;
    case 80:  // Down Arrow key code
    case 's': // s
        prevX = player.row;
        player.row++;
        break;
    case 75:  // Left Arrow key code
    case 'a': // a
        prevY = player.column;
        player.column--;
        break;
    case 77:  // Right Arrow key code
    case 'd': // d
        prevY = player.column;
        player.column++;
        break;
    case 27: // ESCAPE key
    case 'q':
        throw std::runtime_error("Quitting Game!");
        break;
    default:
        break;
    }

    if (player.column >= 0 && player.column < maze.mazeCoords[player.column].size() && player.row >= 0 && player.row < maze.mazeCoords.size()) {
        char item = maze.mazeCoords[player.row][player.column];
        if (item == WALL) {
            player.column = prevY;
            player.row = prevX;
        }
        else if (item == 'E')  {
            return true;
        }
    }
    else {
        player.column = prevY;
        player.row = prevX;
        std::cout << "Invalid position!" << std::endl;
    }

    return false;
}

//  handles players that wanna continue
string handleContinuingPlayer() {
    
}



void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

vector<vector<char>> getMap(int level) {

    switch (level) {
    case 1:
        return {
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, 'S',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
            {WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, WALL, ' ',  WALL},
            {WALL, ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  WALL},
            {WALL, ' ',  WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, WALL},
            {WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, WALL},
            {WALL, WALL, WALL, ' ',  WALL, WALL, WALL, ' ',  ' ',  WALL},
            {WALL, ' ',  WALL, ' ',  ' ',  ' ',  WALL, WALL, ' ',  WALL},
            {WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  'E',  ' ',  WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}};
    case 2:
        return {
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, ' ', ' ', WALL},
            {WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL},
            {WALL, ' ', ' ', WALL, ' ', ' ', ' ', WALL, ' ', ' ', WALL, ' ', ' ', ' ', WALL},
            {WALL, WALL, ' ', WALL, ' ', WALL, ' ', WALL, WALL, ' ', WALL, ' ', WALL, ' ', WALL},
            {WALL, ' ', ' ', ' ', ' ', WALL, ' ', WALL, WALL, ' ', WALL, ' ', WALL, ' ', WALL},
            {WALL, ' ', WALL, WALL, ' ', WALL, ' ', WALL, WALL, ' ', WALL, ' ', WALL, ' ', WALL},
            {WALL, ' ', ' ', WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', WALL, ' ', WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, 'E', WALL}};
    case 3:
        return {
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, 'S', ' ', WALL, ' ', ' ', ' ', WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', WALL},
            {WALL, WALL, ' ', WALL, ' ', WALL, ' ', WALL, ' ', WALL, ' ', WALL, WALL, WALL, ' ', WALL},
            {WALL, ' ', ' ', ' ', ' ', WALL, ' ', ' ', ' ', ' ', ' ', WALL, ' ', ' ', ' ', WALL},
            {WALL, ' ', WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, ' ', WALL, ' ', WALL, WALL, WALL},
            {WALL, ' ', WALL, ' ', ' ', ' ', WALL, ' ', ' ', ' ', ' ', WALL, ' ', ' ', ' ', WALL},
            {WALL, ' ', WALL, ' ', WALL, ' ', WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL},
            {WALL, ' ', WALL, ' ', WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', WALL, ' ', WALL},
            {WALL, ' ', WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, ' ', WALL, WALL, ' ', WALL},
            {WALL, ' ', ' ', ' ', ' ', ' ', ' ', WALL, ' ', ' ', WALL, ' ', ' ', ' ', ' ', WALL},
            {WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, ' ', WALL, WALL, WALL, WALL, WALL, ' ', WALL},
            {WALL, ' ', ' ', ' ', ' ', WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL},
            {WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL},
            {WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', WALL},
            {WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL},
            {WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, ' ', ' ', ' ', ' ', ' ', 'E', WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}};

    case 4:
        return {
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, 'S',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, WALL, WALL, WALL, WALL, ' ',  WALL, WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, ' ',  WALL, WALL, ' ',  WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, WALL, WALL, WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ', ' ',  ' ',  ' ',  WALL},
        {WALL, WALL, WALL, ' ', WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, ' ', WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, ' ', WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, ' ', ' ', ' ', ' ', 'E'},
        {WALL, WALL, WALL, ' ', WALL, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', WALL, WALL, ' ', WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, ' ', WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL}};
        
    case 5:
        return {
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, 'S',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, WALL, WALL, WALL, WALL, ' ',  WALL, WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL},
        {WALL, ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL},
        {WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  WALL},
        {WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, ' ',  WALL, WALL, ' ',  WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, ' ',  WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  WALL, ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, WALL, WALL, WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, ' ',  WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, ' ',  WALL, WALL, WALL, WALL},
        {WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  WALL, ' ',  ' ',  ' ',  ' ',  WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', ' ', ' ', WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', ' ', WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, ' ', ' ', ' ', WALL, ' ', WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', ' ', ' ', WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, ' ', ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', ' ', ' ', ' ', ' ', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, ' ', WALL, WALL},
        {WALL, WALL, WALL, WALL, ' ', WALL, WALL, ' ', ' ', 'E', WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ' ', WALL, WALL, WALL, WALL, WALL}
        };

    default:
        break;
    }

    return {
        {{' '}}
    };
}