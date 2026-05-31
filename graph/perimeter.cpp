#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<int>> grid;

int islandPerimeter() {

    int perimeter = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            if (grid[r][c] == 0)
                continue;

            int edges = 0;

            // up
            if (r == 0 || grid[r - 1][c] == 0)
                edges++;

            // down
            if (r == rows - 1 || grid[r + 1][c] == 0)
                edges++;

            // left
            if (c == 0 || grid[r][c - 1] == 0)
                edges++;

            // right
            if (c == cols - 1 || grid[r][c + 1] == 0)
                edges++;

            perimeter += edges;
        }
    }

    return perimeter;
}

int main() {

    cin >> rows >> cols;

    grid.resize(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cout << islandPerimeter() << "\n";

    return 0;
}