#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int a[5] = {73, 23, 45, 11, 7};
    int x = 10;
    int low = 0, high=100; // suppose you go at speed 100 then it takes 5 min, so 100 is good
    while(low<high) {
        int mid = low+(high-low)/2;
        // calculate the time for mid
        int t = 0;
        // ceil (a/b) is (a+b-1)/b
        rep(i,5) t+=(a[i]+mid-1)/mid;
        // mid is fast --> 1
        if (t<=x) high=mid;
        // mid is slow --> 0
        else low = mid+1;
    }
    cout<<low<<endl;
}