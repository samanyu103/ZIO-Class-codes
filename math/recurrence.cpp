#include<bits/stdc++.h>
using namespace std;
typedef int in;
#define int long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,n) for(int i = 0; i < n; i++)

vvi multiply(vvi a, vvi b) {
    int n = a.size(), p = a[0].size(), q = b.size(), m = b[0].size();
    assert(p==q);
    // output array
    vvi c(n, vi(m));
    rep(i,n) {
        rep(j,m) {
            rep(k, p) c[i][j] += a[i][k]*b[k][j];
        }
    } 
    return c;
}
// a^x
// fast exponentiation
vvi fe(vvi a, int x) {
    int n = a.size();
    vvi I (n, vi(n));
    rep(i,n) I[i][i] = 1;
    if(x==0) return I;
    vvi t = fe(a, x/2);
    t= multiply(t,t);
    if(x&1) t=  multiply(t, a);
    return t;
}

// nth fibonacci
int f(int n) {
    if(n==0) return 0;
    vvi init = {{1}, {0}};
    vvi a = {{1,1}, {1,0}};
    vvi ans = multiply(fe(a, n-1), init);
    return ans[0][0]; 
}

in main() {
    rep(i,10) cout<<f(i)<<" ";
}