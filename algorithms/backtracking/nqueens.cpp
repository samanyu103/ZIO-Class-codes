#include <iostream>
#include <vector>
using namespace std;

vector<int> cols;
vector<int> leftDiagonal;
vector<int> rightDiagonal;
// cur = [2,4,1, 3] means that in the first row, the queen is on the second column etc.
// cur[i] holds the column for queen in row i.

void placeQueens(int i, int n, vector<int>& cur, vector<vector<int>>& result) {
    // reached past the last row
    if (i == n) {
        result.push_back(cur);
        return;
    }
    // placing queen on row i, column j.
    for (int j = 0; j < n; j++) {

        // check if safe
        if (cols[j] || rightDiagonal[i + j] || leftDiagonal[i - j + n - 1])
            continue;

        // place queen
        cols[j] = 1;
        rightDiagonal[i + j] = 1;
        leftDiagonal[i - j + n - 1] = 1;
        cur.push_back(j + 1);

        placeQueens(i + 1, n, cur, result);

        // backtrack
        cur.pop_back();
        cols[j] = 0;
        rightDiagonal[i + j] = 0;
        leftDiagonal[i - j + n - 1] = 0;
    }
}

vector<vector<int>> nQueen(int n) {
    cols.assign(n, 0);
    leftDiagonal.assign(2 * n-1, 0);
    rightDiagonal.assign(2 * n-1, 0);

    vector<vector<int>> result;
    vector<int> cur;

    placeQueens(0, n, cur, result);
    return result;
}

int main() {
    int n = 8;
    vector<vector<int>> ans = nQueen(n);
    cout<<ans.size()<<endl;

    // for (auto& v : ans) {
    //     for (int x : v) cout << x << " ";
    //     cout << endl;
    // }

    return 0;
}