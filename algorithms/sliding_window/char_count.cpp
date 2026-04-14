#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    string s = "xabccabdabc";
    int k=3;
    // cin>>s>>k;
    int n = s.size();
    int j = 0, ans=0;
    array<int, 2> ind = {-1,-1};
    map<char, int> c;
    rep(i,n) {
        while (j<n) {
            // add j, we need to add j first to check if j is good.
            c[s[j]]++;
            // if j is good
            if (c.size()<=k) j++;
            else{
                // j is bad
                //remove j since we added j before.
                c[s[j]]--;
                if (c[s[j]]==0) c.erase(s[j]);
                break;

            }
        }
        // j is bad --> [i, j-1] is good.
        // ans = max(ans, j-i);
        if (j-i>ans) {
            // cout<<i<<" "<<j<<" "<<j-i<<endl;
            ans=j-i;
            ind = {i,j-1};
        }
        // remove left
        c[s[i]]--;
        if (c[s[i]]==0) c.erase(s[i]);
    }
    cout<<ans<<" "<<ind[0]<< " "<<ind[1]<<endl;
}