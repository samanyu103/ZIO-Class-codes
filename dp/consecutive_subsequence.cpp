#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n=4;
    int a[n] = {2,1,3,5};
    int dp[n];
    map<int, int>m;
    int prev[n];
    rep(i,n) {
        dp[i]=1;
        prev[i] = -1;
        if (m.find(a[i]-1)!=m.end()) {
            int l = m[a[i]-1];
            dp[i] +=dp[l];
            prev[i] = l;
        }
        m[a[i]] = i;
    }
    int index = max_element(dp, dp+n)-dp;
    vector<int> seq;
    while(index!=-1) {
        seq.push_back(index);
        index = prev[index];
    }
    reverse(seq.begin(), seq.end());
    cout<<seq.size()<<endl;
    rep(i,seq.size()) {
        cout<<seq[i]<< " ";
    }
    cout<<endl;

}