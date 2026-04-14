#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

int f(int n) {
    if (n==1 or n==2) return 1;
    return f(n-1)+f(n-2);
}
int main() {
    for(int i = 1; i < 11;i++) {
        cout<<f(i)<<" ";
    }
}