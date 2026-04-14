#include<bits/stdc++.h>
using namespace std;
typedef int in;
#define int long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,n) for(int i = 0; i < n; i++)

const int N = 3e5+5;
int M = 998244353;
int fact[N], invfact[N];



int powmod(int x, int n, int m) {
    int res=1;
    while(n) {
        if (n&1) res=res*x%m;
        x=x*x%m;
        n>>=1;
    }
    return res;
}
int inv(int x, int p) {
    return powmod(x, p-2, p);
}


void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = i * fact[i - 1] % M;
    }
    // compute inverse of fact[N-1] once
    invfact[N - 1] = inv(fact[N - 1], M);
    // fill remaining invfacts in reverse
    for (int i = N - 1; i > 0; i--) {
        invfact[i - 1] = i * invfact[i] % M;
    }
}
int choose(int n, int r) {
    return fact[n]*invfact[r]%M*invfact[n-r]%M;
}

void solve() {
    int n, q;
    cin>>n>>q;
    int a[n]={}, b[n]={};
    rep(i,n) {
        cin>>a[i];
        if (i>0) a[i]+=a[i-1];
    }
    rep(i,n) {
        cin>>b[i];
        if(i>0) b[i]+=b[i-1];
    }
    int t = b[n-1];
    int p[t+1]={};
    p[0]=1;
    for(int i =1; i<=t; i++) {
        p[i]=p[i-1]+choose(t,i);
        p[i]%=M;
    }
    // rep(i,n) cout<<a[i]<<" "; cout<<endl;
    // rep(i,n) cout<<b[i]<<" "; cout<<endl;
    rep(i,q) {
        int l, r;
        cin>>l>>r;
        l--,r--;
        int gi = a[r]-(l-1>=0?a[l-1]:0);
        int si = b[r]-(l-1>=0?b[l-1]:0);
        int go = a[n-1]-gi;
        int so = b[n-1]-si;
        int k = go-gi+so+1;
        // cout<<k<<endl;
        int ans = p[t] - (k-1>=0?p[k-1]:0)+M;
        ans%=M;
        int two_n = inv(powmod(2, b[n-1], M), M);
        ans*=two_n;
        ans%=M;
        cout<<ans<<endl;
    }
}
in main() {
    int tt=1;
    // cin>>tt;
    init();
    while(tt--) {
        solve();
    }
}