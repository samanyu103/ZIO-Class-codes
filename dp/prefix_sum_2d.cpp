#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void show(vvi& a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// build prefix sum
void buildprefix(vvi& a, int n, int m, vvi& p) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int s = a[i][j];
            if (i > 0) s += p[i-1][j];
            if (j > 0) s += p[i][j-1];
            if (i > 0 && j > 0) s -= p[i-1][j-1];
            p[i][j] = s;
        }
    }
}

// query sum of rectangle [(l1,r1) to (l2,r2)] (0-based, inclusive)
int rangequery(vvi& p, int l1, int r1, int l2, int r2) {
    int s = p[l2][r2];
    if (l1 > 0) s -= p[l1-1][r2];
    if (r1 > 0) s -= p[l2][r1-1];
    if (l1 > 0 && r1 > 0) s += p[l1-1][r1-1];
    return s;
}

int main() {
    int n = 3, m = 3;

    vvi a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vvi p(n, vi(m, 0));

    buildprefix(a, n, m, p);

    cout << "Prefix matrix:\n";
    show(p, n, m);

    // Example queries
    cout << "\nQuery (0,0) to (1,1): ";
    cout << rangequery(p, 0, 0, 1, 1) << endl; // 1+2+4+5 = 12

    cout << "Query (1,1) to (2,2): ";
    cout << rangequery(p, 1, 1, 2, 2) << endl; // 5+6+8+9 = 28

    cout << "Query (0,1) to (2,2): ";
    cout << rangequery(p, 0, 1, 2, 2) << endl; // 2+3+5+6+8+9 = 33

    return 0;
}