/* C++ program to solve Rat in
a Maze problem using backtracking */
#include <bits/stdc++.h>
using namespace std;

bool solveMazeUtil(int **maze, int n, int m, int x, int y, int **sol);

// funtionn to print the solution of the maze
void printSolution(int **sol, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << " " << sol[i][j] << " ";
        cout << endl;
    }
}

//To check if it is safe to move to the location
bool isSafe(int **maze, int x, int y, int n, int m)
{

    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1)
        return true;

    return false;
}

// solve maze function
bool solveMaze(int **maze, int n, int m, int x, int y)
{
    int **sol;

    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            sol[i][j] = 0;
    }

    if (solveMazeUtil(maze, n, m, x, y, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol, n, m);
    return true;
}

bool solveMazeUtil(int **maze, int n, int m, int x, int y, int **sol)
{

    if (x == m - 1 && y == n - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, n, m) == true)
    {

        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;

        if (solveMazeUtil(maze, n, m, x + 1, y, sol) == true)
            return true;

        if (solveMazeUtil(maze, n, m, x, y + 1, sol) == true)
            return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

// driver program to test above function
int main()
{
    // for number of rows and columns respectively
    int n, m;

    cin >> n >> m;

    int **maze = new int *[n];

    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[m];
    }
    // Taking the input from the user
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];
    }

    solveMaze(maze, n, m, 0, 0);
    return 0;
}
