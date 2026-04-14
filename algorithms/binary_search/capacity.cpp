#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 6;
    int a[n] = {3,6,2,9,10,1};
    int D = 3;
    int low = *max_element(a,a+n);
    int sum=0;
    rep(i,n) sum+=a[i];
    int high = sum;
    while(low<high) {
        int mid = low+(high-low)/2;
        int total=0, ans=1;
        rep(i,n) {
            if (total+a[i]<= mid) {
                total+=a[i];
            }else {
                ans++;
                total=a[i];
            }
        }
        // good (1)
        if (ans<=D) high=mid;
        else low=mid+1;
    }
    cout<<low<<endl;

}