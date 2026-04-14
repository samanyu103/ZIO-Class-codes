#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    string s="abcadbhfbsa";
    // cin>>s;
    int n = s.size();
    int j = 0, ans=0;
    map<char, int>m;
    rep(i,n) {
        while(j<n) {
            if (!m[s[j]]) {
                m[s[j]]++;
                j++;
            }
            else break;
        }
        ans=max(ans, j-i);
        m[s[i]]--;
    }
    cout<<ans<<endl;
}