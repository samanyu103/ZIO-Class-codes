#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    string s="abcadbhfbsa";
    // cin>>s;
    int n = s.size();
    int j = 0, ans=0;
    set<char> c;
    rep(i,n) {
        while (j<n and c.find(s[j]) == c.end()) {
            // j is good that is s[j] is not in set
            c.insert(s[j]);
            j++;
        }
        // j is bad --> [i, j-1] is good.
        ans = max(ans, j-i);
        c.erase(s[i]);
    }
    cout<<ans<<endl;
}