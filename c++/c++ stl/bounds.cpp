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
    int a[n] =  {5,7,2,7,1};
    sort(a, a+n);
    // /1, 2, 5, 7, 7
    int index = lower_bound(a, a+n, 7)-a;
    cout<<index<<endl;
}