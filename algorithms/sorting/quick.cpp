#include <iostream>
using namespace std;

int partition(int a[], int left, int right) {
    int pivot = a[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (i < j && a[i] <= pivot) i++;
        while (i<j and a[j] > pivot) j--;
        // a[i]>pivot and a[j]<= pivot
        if (i >= j) break;

        swap(a[i], a[j]);
    }
    // a[j]<= pivot, j is the correct position for pivot.
    swap(a[left], a[j]);
    return j;
}

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
}

int main() {
    int a[] = {28, 14, 37, 9, 21, 45, 16};
    int n = 7;

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}