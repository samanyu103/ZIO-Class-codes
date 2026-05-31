#include<bits/stdc++.h>
using namespace std;
typedef int in;
#define int long long int
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,n) for(int i = 0; i < n; i++)

// note that you must use long long in calculations
const int N = 1e6;
int M = 1e9+7;
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
    invfact[0]=1;
    for (int i = 1; i < N; i++) {
        invfact[i] = inv(i, M) * invfact[i - 1] % M;
    }

}
int choose_precomputed(int n, int r) {
    return fact[n]*invfact[r]%M*invfact[n-r]%M;
}
int choose(int n, int r) {
    int res=1;
    rep(i,r) {
        res=res*(n-i)%M*inv(r-i, M)%M;
    }
    return res;
}


in main() {
    cout<<inv(4, 998244353);
    cout<<choose(4, 2)<<endl;
    init();
    cout<<choose_precomputed(4,2)<<endl;


}