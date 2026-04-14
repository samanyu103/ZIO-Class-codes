#include <iostream>
using namespace std;

int partition(int a[], int left, int right) {
    int pivot = a[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (i <= right && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        // a[i]>pivot and a[j]<= pivot
        if (i >= j) break;

        swap(a[i], a[j]);
    }
    // a[j]<= pivot, j is the correct position for pivot.
    swap(a[left], a[j]);
    return j;
}

int Find(int k, int a[], int left, int right) {
    int p = partition(a, left, right);

    if (p == k - 1)
        return a[p];
    else if (p < k - 1)
        return Find(k, a, p + 1, right);
    else
        return Find(k, a, left, p - 1);
}

int main() {
    int a[] = {12, 1, 3, 7, 3, 4, 4};
    int n = 7;
    int k = 3;

    cout << Find(k, a, 0, n - 1) << endl;
}