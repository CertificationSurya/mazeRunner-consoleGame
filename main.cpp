#include <iostream>
#include <vector>
#include <conio.h>
#include <utility>
#include <windows.h>

using namespace std;

vector<vector<char>> getMap(int level);

// components
class Player
{
public:
    int column, row;
    char playerLook;

    Player(int column, int row, char playerLook) : column(column), row(row), playerLook(playerLook){};
    void rePosition(int col, int row)
    {
        this->column = col;
        this->row = row;
    }
};

class Maze
{
public:
    vector<vector<char>> mazeCoords;
    pair<int, int> startCoord = {1, 1};
    pair<int, int> endCoord = {8, 7};
    // for maze
    void initializeMaze(int level)
    {
        mazeCoords = getMap(level);
    }

    void printMaze(const Player &player)
    {
        for (int i = 0; i < mazeCoords.size(); ++i)
        {
            for (int j = 0; j < mazeCoords[i].size(); ++j)
            {
                if (i == player.row && j == player.column)
                {
                    std::cout << player.playerLook;
                }
                else
                {
                    std::cout << mazeCoords[i][j];
                }
            }
            std::cout << '\n';
        }
    };
};

// struct Wall {
//     pair<int, int> cell1;
//     pair<int, int> cell2;
// };

// Utilities function
// handle keypress
bool handleKeyPress(char, Player &, Maze &);
void clearScreen();

int main()
{
    int level = 1;
    Maze maze;
    maze.initializeMaze(level);

    cout << "Enter the asci code for your character: ";
    char playerLook = _getch();
    Player player(maze.startCoord.first, maze.startCoord.second, playerLook);

    while (true)
    {
        maze.printMaze(player);
        char key = _getch();
        bool win = handleKeyPress(key, player, maze);
        if (win)
        {
            if (level == 3)
            {
                clearScreen();
                cout << "\033[1m";
                cout << "Congratulation, You Won!";
                cout << "\033[0m";
                Sleep(2000);
                break;
            }
            else
            {
                cout << "\033[1m";
                cout << "On to the next level: lv. " << ++level;
                cout << "\033[0m";
                player.rePosition(maze.startCoord.first, maze.startCoord.second);
                maze.initializeMaze(level);
                Sleep(1000);
            }
        }
        clearScreen();
    }

    return 0;
}

// utilities function
bool handleKeyPress(char key, Player &player, Maze &maze)
{
    int prevX = player.row;
    int prevY = player.column;

    switch (key)
    {
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
        throw std::runtime_error("BreakException");
        break;
    default:
        break;
    }

    if (player.column >= 0 && player.column < maze.mazeCoords[player.column].size() && player.row >= 0 && player.row < maze.mazeCoords[player.row].size())
    {
        char item = maze.mazeCoords[player.row][player.column];
        if (item == '#')
        {
            player.column = prevY;
            player.row = prevX;
        }
        else if (item == 'E')
        {
            return true;
        }
    }
    else
    {
        player.column = prevY;
        player.row = prevX;
        std::cout << "Invalid position!" << std::endl;
    }

    return false;
}

vector<vector<char>> getMap(int level)
{

    switch (level)
    {
    case 1:
        return {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'S', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#'},
            {'#', '#', '#', ' ', '#', '#', '#', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', 'E', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
    case 2:
        return {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
            {'#', ' ', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'E', '#'}};
    case 3:
        return {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'S', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
            {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    default:
        break;
    }

    return {
        {' ', ' '},
        {' ', ' '}};
}
void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}