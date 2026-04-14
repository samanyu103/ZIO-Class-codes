#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int x = 3,y=13; //14 7 8 4 2 3 answer 6
    int ans=0;
    while(y>x) {
        if (y&1) y++;
        else y>>=1;
        ans++;
    }
    ans+=x-y;
    cout<<ans<<endl;
}