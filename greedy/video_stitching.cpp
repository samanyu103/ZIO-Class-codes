#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 4;
    array<int, 2> a[n] = {{1,5},{2,6}, {3, 7}};
    // array<int, 2> a[n] = {{1,5},{2,6}, {3, 7}, {8, 9}};
    sort(a, a+n);
    int ans=1;
    bool possible=1;
    int i =0;
    int e = a[0][1];
    while(i<n) {
        if (a[i][0]>e) {
            possible=0;
            break;
        }
        int maxe=INT_MIN;
        while(a[i][0]<=e) {
            maxe=max(maxe, a[i][1]);
            i++;
        }
        e=maxe;
        ans++;
    }
    if (!possible) cout<<-1<<endl;
    else cout<<ans<<endl;


}