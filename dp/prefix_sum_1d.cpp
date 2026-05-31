#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)



void buildprefix(int a[], int n, int p[]) {
    rep(i,n) {
        p[i] = a[i] + (i-1>=0?p[i-1]:0);
    }
    rep(i,n) cout<<p[i]<< " ";
}

int rangequery(int p[], int n, int l, int r) {
    // invalid indices
    if (r>n-1||r<0||l>n-1||l<0) return 0;
    return p[r] - (l-1>=0?p[l-1]:0);
}

int main() {
    int n = 5;
    int a[n] = {1,-3,2,4,-1};
    int p[n] = {};
    buildprefix(a,n, p);
    cout<<endl;
    int l = 1, r=3;//0 based indices
    cout<<rangequery(p, n, l, r)<<endl;

}