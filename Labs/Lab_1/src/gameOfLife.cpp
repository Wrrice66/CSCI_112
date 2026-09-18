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
    std::string currentLine;
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
        getline(fin, currentLine);
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
            std::cout << board[i][k]->state;
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
    int mainX = curCell->x;
    int mainY = curCell->y;
    int neighX, neighY;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            neighX = mainX + i;
            neighY = mainY + j;
            if (neighX < 0 || neighY < 0 || neighX > 10 || neighY > boardSize)
                continue;
            else if (board[neighX][neighY]->state == 1)
                curCell->numLiveNeighbors ++;
            else
                continue;
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
    Cell* currCell;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            currCell = board[i][j];
            findNumNeighbors(board, boardSize, currCell);
            if (currCell->state == 1)
            {
                switch (currCell->numLiveNeighbors)
                {
                    case 1:
                        currCell->state = 0;
                    case 2:
                        continue;
                    case 3:
                        continue;
                    case 4:
                        currCell->state = 0;
                    case 5:
                        currCell->state = 0;
                    case 6:
                        currCell->state = 0;
                    case 7:
                        currCell->state = 0;
                    case 8:
                        currCell->state = 0;
                }
            }
            else
            {
                if (currCell->numLiveNeighbors == 3)
                    currCell->state = 1;
                else
                    continue;
            }
        }
    }
    return cellChanged;
}


// Old code for findNumNeighbors

/*
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
*/


// Old code for updateCellState

/*
            if (board[i][j]->state == 1)
            {
                if (board[i][j]->numLiveNeighbors < 2)
                {
                    board[i][j]->state = 0;
                    cellChanged = true;
                }
                else if (board[i][j]->numLiveNeighbors == 2||board[i][j]->numLiveNeighbors == 3)
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
*/