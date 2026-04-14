#include <bits/stdc++.h>
using namespace std;

// Count elements ≤ mid in O(n)
int countLessEqual(vector<vector<int>>& matrix, int mid) {
    int n = matrix.size();
    int i = n - 1, j = 0;
    int count = 0;

    while (i >= 0 && j < n) {
        if (matrix[i][j] <= mid) {
            count += (i + 1); // all elements above are ≤ mid
            j++;
        } else {
            i--;
        }
    }
    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int cnt = countLessEqual(matrix, mid);

        if (cnt < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

// Example usage
int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    cout << kthSmallest(matrix, k) << endl; // Output: 13
    return 0;
}