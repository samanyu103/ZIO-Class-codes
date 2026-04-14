#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 11;
    int a[n] = { 0, 0 ,0 ,0 ,0 ,1, 1, 1, 1, 1, 1};
    int low= 0, high=11;
    while(low<high) {
        int mid = (low+high)/2;
        if (a[mid]) high=mid;
        else low=mid+1;
    }
    cout<<low<<endl;
}