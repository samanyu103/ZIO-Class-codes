#include <iostream>
using namespace std;


void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // find the index of the smallest element
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // swap with the first element of the unsorted part
        swap(a[i], a[minIndex]);
    }

}

int main() {
    int a[] = {5,3,8,4};
    int n = 4;
    selection(a,n);
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    cout<<endl;
}