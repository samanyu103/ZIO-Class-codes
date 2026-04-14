#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

int main() {
    int n = 6;
    int a[n] = {2,4,1, 1, 3, 2};
    int cnt = n==1?0:1;
    int j = a[0], i=0;
    while(1) {
        int jj=j;
        if (j>=n-1) {
            break;
        }
        while(i<=j) {
            jj = max(jj,a[i]+i);
            i++;
        }
        if (jj==j) {
            cnt=-1;
            break;
        }
        j=jj;
        cnt++;
    }
    cout<<cnt<<endl;
}
