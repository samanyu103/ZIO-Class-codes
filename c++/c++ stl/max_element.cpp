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
    int index = max_element(a, a+n)-a;
    cout<<index<<endl;
}