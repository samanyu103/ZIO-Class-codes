#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 11;
    int a[n] = {1,4,3,5,2,6,8,3,4,5,2};
    int target = 19;
    bool found=0;
    map<int, array<int,2>>m;
    rep(i,n) {
        for(int j = i+1; j < n; j++) {
            if (m.find(target-a[i]-a[j])!=m.end()) {
                found = 1;
                array<int,2> p = m[target-a[i]-a[j]];
                cout<<p[0]<<" "<<p[1]<<" "<<i<<" "<<j<<endl;
                break;
            }
        }
        if(found) break;
        rep(j,i) {
            m[a[j]+a[i]] = {j,i};
        }
    }
    if (!found) cout<<-1<<endl;
}