#include <iostream>
using namespace std;
#define rep(i,n) for(int i = 0; i<n;i++)


void incrementArray(int arr[], int n) {
    rep(i,n) {
        arr[i]+=1;
    }
}
void printarray(int arr[], int n) {
    rep(i,n) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int a[5] = {1,2,3,4,5};
    incrementArray(a, 5);
    printarray(a,5);
}