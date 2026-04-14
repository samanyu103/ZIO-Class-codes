#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 5;
    int a[n] = {73,24,12,94,13};
    int D = 204;
    sort(a,a+n);
    int ans=0;
    rep(i,n) {
        if (D>=a[i]) {
            D-=a[i];
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
}