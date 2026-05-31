#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int gcd(int a, int b) {
    if (a==0) return b;
    return gcd(b%a, a);
}

int main() {
    int a = 48, b = 18;
    cout<<gcd(a, b);
}