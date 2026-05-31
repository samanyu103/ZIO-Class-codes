#include <bits/stdc++.h>
using namespace std;

int rows, cols;
vector<vector<int>> grid;

int dfs(int r, int c) {

    // out of bounds
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return 0;

    // water
    if (grid[r][c] == 0)
        return 0;

    // sink this land cell
    grid[r][c] = 0;

    int area = 1;

    area += dfs(r + 1, c);
    area += dfs(r - 1, c);
    area += dfs(r, c + 1);
    area += dfs(r, c - 1);

    return area;
}

int maxAreaOfIsland() {

    int maxArea = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

            if (grid[r][c] == 1) {

                int area = dfs(r, c);

                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main() {

    cin >> rows >> cols;

    grid.resize(rows);

    for (int i = 0; i < rows; i++) {
        grid[i].resize(cols);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cout << maxAreaOfIsland() << "\n";

    return 0;
}