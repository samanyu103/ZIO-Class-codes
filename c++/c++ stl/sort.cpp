#include<bits/stdc++.h>
using namespace std;
typedef int in;
#define int long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,n) for(int i = 0; i < n; i++)

in main() {
    int n = 5;
    int a[n] =  {5,3,2,7,1};
    sort(a, a+n);
    rep(i,n) cout<<a[i]<<" ";
    cout<<endl;
}