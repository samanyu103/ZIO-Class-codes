#include <bits/stdc++.h>
using namespace std;

// Generate subset sums using include/exclude
void generateSums(int arr[], int n, int i, int currentSum, vector<int> &sums) {
    if (i == n) {
        sums.push_back(currentSum);
        return;
    }

    // Include
    generateSums(arr, n, i + 1, currentSum + arr[i], sums);

    // Exclude
    generateSums(arr, n, i + 1, currentSum, sums);
}

int minAbsDifference(int a[], int n, int target) {
    int half = n / 2;

    int n1 = half;
    int n2 = n - half;

    // Properly sized arrays
    int leftA[n1], rightA[n2];

    // Copy elements
    for (int i = 0; i < n1; i++) {
        leftA[i] = a[i];
    }
    for (int i = 0; i < n2; i++) {
        rightA[i] = a[half + i];
    }

    vector<int> left, right;

    // Generate subset sums
    generateSums(leftA, n1, 0, 0, left);
    generateSums(rightA, n2, 0, 0, right);

    sort(right.begin(), right.end());

    int result = INT_MAX;

    for (int s1 : left) {
        int need = target - s1;

        auto it = lower_bound(right.begin(), right.end(), need);

        if (it != right.end()) {
            result = min(result, abs(s1 + *it - target));
        }

        if (it != right.begin()) {
            --it;
            result = min(result, abs(s1 + *it - target));
        }
    }

    return result;
}

int main() {
    int a[] = {5, -7, 3, 5};
    int n = 4;
    int target = 6;

    cout << minAbsDifference(a, n, target) << endl;

    return 0;
}