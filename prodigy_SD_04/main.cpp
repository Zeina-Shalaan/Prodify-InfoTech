#include <iostream>
using namespace std;
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            std::cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Function to check if it's safe to place a number at grid[row][col]
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to find an empty cell (represented by 0 in the grid)
bool findEmptyCell(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

// Main Sudoku Solver function using Backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // If there are no empty cells, we are done
    if (!findEmptyCell(grid, row, col))
        return true;

    // Try numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Check if it's safe to place the number
        if (isSafe(grid, row, col, num)) {
            // Make tentative assignment
            grid[row][col] = num;

            // Recursively attempt to solve the rest of the grid
            if (solveSudoku(grid))
                return true;

            // If placing num doesn't lead to a solution, undo & backtrack
            grid[row][col] = 0;
        }
    }

    // Trigger backtracking
    return false;
}

int main() {
    // Example Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Unsolved sudoku"<<endl;
    for (int i=0; i< N;i++)
    {
        for(int j =0; j< N; j++)
        {
         cout << grid[i][j]  << " ";
        }
        cout << endl;
    }


    cout << "Solved sudoku"<< endl;

    if (solveSudoku(grid))
        printGrid(grid);
    else
        std::cout << "No solution exists" << std::endl;

    return 0;
}
