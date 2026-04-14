#include <bits/stdc++.h>
using namespace std;

void countingSortByDigit(int a[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count digit occurrences
    for(int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    // Prefix sums
    for(int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    // Build output aay (right to left for stability)
    for(int i = n-1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // Copy back to original aay
    for(int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void radixSort(int a[], int n) {
    int maxVal = *max_element(a, a+n);

    int exp = 1;

    // Process each digit
    while(maxVal / exp >= 1) {
        countingSortByDigit(a, n, exp);
        exp *= 10;
    }
}

int main() {
    int a[] = {7, 45, 302, 19, 250, 8, 104, 63};
    int n = sizeof(a) / sizeof(a[0]);

    radixSort(a, n);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}