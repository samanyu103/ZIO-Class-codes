#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int a[5] = {1,2,4,7,8};
    int low= 0, high=4, ans=-1;
    int target=6;
    while(low<=high) {
        int mid = (low+high)/2;
        if (a[mid]==target) {
            ans= mid;
            break;
        }
        else if (a[mid]>target) high= mid-1;
        else low = mid+1;
    }
    cout<<ans<<endl;

}