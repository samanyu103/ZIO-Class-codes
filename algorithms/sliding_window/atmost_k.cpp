#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 9;
    int a[n] = {1,3,1, 4,2,2,4,2,5};
    int k = 3;
    map<int, int>m;
    int j=0,ans=0;
    rep(i,n) {
        while(j<n) {
            // add j
            m[a[j]]++;
            // if j is good
            if (m.size()<=k)j++;
            else{
                // j is bad. remove j since you added it before
                m[a[j]]--;
                if (m[a[j]]==0) m.erase(a[j]);
                break;
            }
        }
        // [i..j-1] is good
        ans+=j-i;
        // remove i
        m[a[i]]--;
        if(m[a[i]]==0) m.erase(a[i]);
    }
    cout<<ans<<endl;
}