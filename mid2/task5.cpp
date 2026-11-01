#include <iostream>
#include <string>
using namespace std;

const int ROWS = 6;                    // seating grid: 6 rows
const int COLS = 8;                    // and 8 columns
const int COURSES = 4;                 // number of courses to seat

// How many arrangements to PRINT. All of them are still found and counted.
// Set to 100000 if you really want to print every single one.
const int SHOW_LIMIT = 10;

// Damaged desk: seat (3,3) counting from 1  ->  row index 2, column index 2
const int BAD_ROW = 2;
const int BAD_COL = 2;

string courseName[COURSES] = {"Programming", "Database Systems",
                              "Operating Systems", "Computer Networks"};
char courseLetter[COURSES] = {'P', 'D', 'O', 'C'};

// Can we seat a course at (row, col)?  Only look at the rows ABOVE us.
bool isSafe(int board[ROWS][COLS], int row, int col)
{
    // Damaged desk
    if(row == BAD_ROW && col == BAD_COL)
    {
        return false;
    }

    // Same column
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] != 0)
        {
            return false;
        }
    }

    // Upper-left diagonal
    int i = row - 1;
    int j = col - 1;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] != 0)
        {
            return false;
        }
        i--;
        j--;
    }

    // Upper-right diagonal
    i = row - 1;
    j = col + 1;
    while(i >= 0 && j < COLS)
    {
        if(board[i][j] != 0)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

void printBoard(int board[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] != 0)
            {
                cout << courseLetter[board[i][j] - 1] << "  ";
            }
            else
            {
                cout << ".  ";
            }
        }
        cout << endl;
    }

    // Also list each course with its seat (counting from 1)
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board[i][j] != 0)
            {
                cout << "  " << courseName[board[i][j] - 1]
                     << " -> row " << i + 1 << ", column " << j + 1 << endl;
            }
        }
    }
}

// "placed" = how many courses are seated so far
void solve(int board[ROWS][COLS], int row, int placed, int &count)
{
    if(placed == COURSES)              // base case: all 4 courses seated
    {
        count++;
        if(count <= SHOW_LIMIT)
        {
            cout << "Arrangement " << count << ":" << endl;
            printBoard(board);
            cout << endl;
        }
        return;
    }

    if(row == ROWS)                    // ran out of rows before seating everyone
    {
        return;
    }

    // Option 1: seat the next course somewhere in THIS row
    for(int col = 0; col < COLS; col++)
    {
        if(isSafe(board, row, col))
        {
            board[row][col] = placed + 1;            // CHOOSE (1 = Programming, 2 = Database, ...)
            solve(board, row + 1, placed + 1, count);  // EXPLORE
            board[row][col] = 0;                     // BACKTRACK
        }
    }

    // Option 2: leave this row empty (NOT allowed for the first row)
    if(row != 0)
    {
        solve(board, row + 1, placed, count);
    }
}

int main()
{
    int board[ROWS][COLS] = {0};
    int count = 0;

    solve(board, 0, 0, count);

    cout << "Total valid arrangements: " << count << endl;
    return 0;
}