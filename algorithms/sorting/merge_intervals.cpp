#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
#define pb push_back
using namespace std;

int main() {
    array<int, 2> a[4] = {{1,3},{2,6},{8,10},{15,18}};
    int n = 4;
    vector<array<int,2>> result;
    sort(a,a+4);
    int s = a[0][0], e = a[0][1];
    for(int i = 1; i< n; i++) {
        if (a[i][0]<=e) e = max(e, a[i][1]);
        else  {
            result.pb({s,e});
            s=a[i][0];
            e= a[i][1];
        }
    }
    result.pb({s,e});
    rep(i, result.size()) cout<<"["<<result[i][0]<<","<<result[i][1]<<"] ";
    cout<<endl;
}