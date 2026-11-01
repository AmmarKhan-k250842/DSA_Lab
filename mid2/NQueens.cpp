#include <iostream>
#include <string>
using namespace std;


# define N 4


bool isSafe(int board[N][N], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }


    int i = row - 1;
    int j = col - 1;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    i = row - 1;
    j = col + 1;
    while(i >= 0 && j < N)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool solve(int board[N][N], int row)
{
    if(row == N)
    {
        return true;
    }

    for(int col = 0; col < N; col++)
    {
        if(isSafe(board, row, col))
        {
            board[row][col] = 1;

            if(solve(board, row + 1))
            {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int board[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == 1)
            {
                cout << "Q  ";
            }
            else
            {
                cout << ".  ";
            }
        }
        cout << endl;
    }
}


int main()
{
    int board[N][N] = {0};

    if(solve(board, 0))
    {
        cout << "Solution Found:" << endl;
        printBoard(board);
    }
    else
    {
        cout << "No Solution Exists." << endl;
    }

    return 0;
}
