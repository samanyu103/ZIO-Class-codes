#include <iostream>
using namespace std;




void bubble(int a[], int n) {

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {
    int a[] = {5,3,8,4};
    int n = 4;
    bubble(a,n);
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    cout<<endl;
}