#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;


int pow(int x, int n) {
    if (n==0) return 1;
    int t = pow(x,n/2);
    t*=t;
    if (n&1) t*=x;
    return t;
}
int pow2(int x, int n) {
    int res=1;
    while(n) {
        if (n&1) res*=x;
        x*=x;
        n>>=1;
    }
    return res;
}

int main() {
    int x, n;
    cin>>x>>n;
    cout<<pow(x, n)<< pow2(x, n)<<endl;
}