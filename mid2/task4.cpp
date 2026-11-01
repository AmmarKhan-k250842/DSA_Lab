#include <iostream>
#include <string>
using namespace std;

# define N 4
# define Max_Paths 200

void helper(int mat[N][N], int r, int c, string path, string ans[], int &count)
{
    if(r < 0 || c < 0 || r >= N || c >= N || mat[r][c] != 1)
    {
        return;
    }

    if(r == N - 1 && c == N - 1)
    {
        if(count < Max_Paths)
        {
            ans[count] = path;
            count++;
        }
        return;
    }

    mat[r][c] = -1;

    helper(mat, r - 1, c, path + "U", ans, count);
    helper(mat, r + 1, c, path + "D", ans, count);
    helper(mat, r, c - 1, path + "L", ans, count);
    helper(mat, r, c + 1, path + "R", ans, count);
    
    mat[r][c] = 1;
}

int findPaths(int mat[N][N], string ans[])
{
    int count = 0;
    string path = "";
    helper(mat, 0, 0, path, ans, count);
    return count;
}


int main()
{
    int mat[N][N] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    string ans[Max_Paths];

    int count = findPaths(mat, ans);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << mat[i][j] << "  ";
        }

        cout << endl;
    }

    cout << "\n" << endl;

    cout << "Paths Found: " << endl;
    for(int x = 0; x < count; x++)
    {
        cout << ans[x] << endl;
    }

    return 0;
}