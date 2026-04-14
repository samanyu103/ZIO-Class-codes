#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    string s="abcxccab";
    int k=2;
    int n=s.size();
    int j=0, ans=0;
    map<char, int> m;
    int mf = 0;
    rep(i,n) {
        while(j<n) {
            // add j
            m[s[j]]++;
            mf =max(mf, m[s[j]]);
            // j is good
            if (j-i+1-mf<=k) j++;
            else {
                // j is bad
                m[s[j]]--;
                // no need to update mf
                break;
            }
        }
        // [i..j-1] is good
        ans = max(ans, j-i);
        m[s[i]]--;
    }
    cout<<ans<<endl;

}