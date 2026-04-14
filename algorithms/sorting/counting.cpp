#include<iostream>
#define rep(i,n) for(int i = 0; i<n; i++)
using namespace std;


void counting(int a[], int n, int k) {

}
int main() {
    int n = 7, k=8;
    int a[n] = {4, 2, 2, 8, 3, 3, 1}, b[n] = {};
    int c[k+1]={}; // frequeny count
    rep(i,n) c[a[i]]++;
    for(int i = 1; i<=k;i++) c[i]+=c[i-1]; //prefix sum
    //right to left for stability
    for(int i =n-1; i>=0; i--) {
        b[--c[a[i]]]=a[i];
    }
    for(int i = 0; i < n; i++)cout << b[i] << " ";
    cout<<endl; 
}