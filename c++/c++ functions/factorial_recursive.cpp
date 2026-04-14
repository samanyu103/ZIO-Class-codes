#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)


int factorial(int n) {
    if (n==0) return 1;
    return n*factorial(n-1);
}
int main() {
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
}