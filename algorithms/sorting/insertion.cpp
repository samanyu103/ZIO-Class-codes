#include <iostream>
using namespace std;

void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // Shift elements greater than key to the right
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        // a[j]<= key, so place at position j+1.
        // Insert key in the correct position
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {5,3,8,4};
    int n = 4;
    insertion(a,n);
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    cout<<endl;
}