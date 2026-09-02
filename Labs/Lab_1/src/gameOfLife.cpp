#include "../include/gameOfLife.hpp"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int e = 0; e < 10; e++)
        {
            board[i][e] = new Cell;
            board[i][e]->x = i;
            board[i][e]->y = e;
            // board[i][e]->state = 0;
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    ifstream fin;
    string saveName;
    char currentLine[10];
    while(!fin.is_open())
    {
        std::cout << "Enter name of savefile: " << std::endl;
        std::cin >> saveName;
        fin.open(saveName);
        if (!fin.is_open())
            std::cout << "File not found. Try again." << std::endl;
    }
    for (int x = 0; x < boardSize; x++)
    {
        fin.getline(currentLine, 10);
        for (int y = 0; y < 10; y++)
        {
            board[x][y]->state = (currentLine[y] - '0');
        }
    }
    fin.close();
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            std::cout << board[k][i]->state;
        }
        std::cout << std::endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{
    for (int y = 0; y < boardSize; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            curCell = board[x][y];
            if (x > 0 && y > 0)
            {
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (curCell != board[x-i][y-j])
                            curCell->numLiveNeighbors += board[x-i][y-j]->state;
                        else
                            continue;
                    }
                }
            }
            else if (x > 0 && y == 0)
            {
                for (int i = -1; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        if (curCell != board[x-i][y-j])
                            curCell->numLiveNeighbors += board[x-i][y-j]->state;
                        else
                            continue;
                    }
                }
            }
            else if (x == 0 && y > 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (curCell != board[x-i][y-j])
                            curCell->numLiveNeighbors += board[x-i][y-j]->state;
                        else
                            continue;
                    }
                }
            }
            else 
            {
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        if (curCell != board[x-i][y-j])
                            curCell->numLiveNeighbors += board[x-i][y-j]->state;
                        else
                            continue;
                    }
                }
            }
        }
    }
}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    bool cellChanged = false;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (board[i][j]->state == 1)
            {
                if (board[i][j]->numLiveNeighbors < 2)
                {
                    board[i][j]->state = 0;
                    cellChanged = true;
                }
                else if (board[i][j]->numLiveNeighbors == 2||3)
                    continue;
                else if (board[i][j]->numLiveNeighbors > 3)
                {
                    board[i][j]->state = 0;
                    cellChanged = true;
                }
            }
            else
            {
                if (board[i][j]->numLiveNeighbors == 3)
                {
                    board[i][j]->state = 1;
                    cellChanged = true;
                }
                else
                    continue;
            }
        }
    }
    return cellChanged;
}