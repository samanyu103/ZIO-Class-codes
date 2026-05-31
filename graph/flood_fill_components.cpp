#include <bits/stdc++.h>
using namespace std;

int rows, cols;

vector<vector<char>> grid;

void dfs(int r, int c) {

    // out of bounds
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;

    // water
    if (grid[r][c] == '0')
        return;

    // sink this land cell
    grid[r][c] = '0';

    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

int numIslands() {

    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == '1') {

                count++;

                // erase entire connected component
                dfs(i, j);
            }
        }
    }

    return count;
}

int main() {

    cin >> rows >> cols;

    grid.resize(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cout << numIslands() << "\n";

    return 0;
}