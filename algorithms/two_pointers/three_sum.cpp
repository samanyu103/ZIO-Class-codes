#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 7;
    int a[n] = {5,2,5,2,3,1,7};
    int target=15;
    sort(a,a+n);
    bool found=0;
    rep(i,n) {
        int j = i+1, k = n-1;
        int t = target -a[i];
        while(j<k) {
            int sum = a[j]+a[k];
            if (sum == t) {
                cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                found = 1;
                break;
            }
            else if (sum < t) j++;
            else k--;
        }
    }
}