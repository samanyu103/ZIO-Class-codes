#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

vi f(int n) {
    vi v;
    for(int i = 2; i*i<=n; i++) {
        while (n%i==0) {
            v.pb(i);
            n/=i;
        }
    }
    // 2^2*11 11 left over.
    // there will be atmost 1 prime factor > root(n).
    if (n>1) v.pb(n);
    return v;
}

int main() {
    int n=1048;
    vi v = f(n);
    for(int x: v) cout<<x<<" ";
}