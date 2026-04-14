#include <bits/stdc++.h>
using namespace std;

// r[i][d] = is digit d present in row i
// c[j][d] = is digit d present in column j
// b[i/3][j/3][d] = is digit d present in that 3x3 box

bool r[9][10], c[9][10], b[3][3][10];

bool solve(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') {

                for (int d = 1; d <= 9; d++) {
                    if (!r[i][d] && !c[j][d] && !b[i/3][j/3][d]) {

                        // place digit
                        board[i][j] = char('0' + d);
                        r[i][d] = c[j][d] = b[i/3][j/3][d] = true;

                        if (solve(board)) return true;

                        // backtrack
                        board[i][j] = '.';
                        r[i][d] = c[j][d] = b[i/3][j/3][d] = false;
                    }
                }

                return false; // no valid digit
            }
        }
    }

    return true; // solved
}

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // initialize helper arrays
    memset(r, false, sizeof(r));
    memset(c, false, sizeof(c));
    memset(b, false, sizeof(b));

    // fill based on initial board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int d = board[i][j] - '0';
                r[i][d] = true;
                c[j][d] = true;
                b[i/3][j/3][d] = true;
            }
        }
    }

    solve(board);

    // print solved board
    cout << "Solved Sudoku:\n\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}