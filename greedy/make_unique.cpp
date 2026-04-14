#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] = {1,1,2,2,3,7};
    sort(a, a+n);
    int ans=0;
    for(int i = 1; i<n; i++) {
        if (a[i]<=a[i-1]) {
            int prev = a[i];
            a[i] = a[i-1]+1;
            ans+=a[i]-prev;
        }
    }
    cout<<ans<<endl;
}