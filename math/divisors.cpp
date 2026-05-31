#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

vi divisors(int n) {
    vi v;
    for(int i = 1; i*i<=n; i++) {
        if (n%i==0) {
            v.pb(i);
            if (i*i!=n) v.pb(n/i);
        }
    }
    sort(v.begin(),v.end());
    return v;
}

int main() {
    int n = 1048;
    vi div = divisors(n);
    for(int a: div) cout<<a<<" ";
}