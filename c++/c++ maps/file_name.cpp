#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n;
    cin>>n;
    string a[n];
    rep(i,n) cin>>a[i];
    map<string , int > m;
    string b[n];
    rep(i,n) {
        b[i] = a[i];
        if (m[a[i]]) b[i] += m[a[i]]+'0';
        m[a[i]]++;
    }
    rep(i,n) cout<<b[i]<<endl;
}