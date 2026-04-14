#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 6;
    int a[n] = {1,4,7,9,13,56};
    int target = 13;
    int l=0, r=n-1;
    bool found=0;
    // we want different indices so l cannot be equal to r.
    while(l<r) {
        int s = a[l]+a[r];
        if (s==target) {
            found = 1;
            cout<<a[l]<< " "<<a[r];
            break;
        }
        else if (s<target) l++;
        else r--;
    }
    if (!found) cout<<-1<<endl;
}