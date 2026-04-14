#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 3;
    int a[n] = {1,2,3};
    vector<int> result;
    rep(mask, 1<<n) {
        // mask represents the subset
        int sum = 0;
        // ith bit is set
        rep(i,n){
            if (mask &  (1<<i))
                sum+=a[i];
        }
        result.push_back(sum);
    }
    rep(i,result.size()) cout<<result[i]<<endl;
}