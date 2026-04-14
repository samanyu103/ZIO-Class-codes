#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    int n = 8;
    int a[n] = {4,2,7,3,8,5,6,1};
    int l = 0, r = n-1, ml=-1, mr=-1;
    int max_area = INT_MIN;
    while(l<r) {
        int area = min(a[l] ,a[r])*(r-l);
        if (area>max_area) {
            max_area=area;
            ml=l;
            mr=r;
        }
        if (a[l]<a[r]) l++;
        else r--;
    }
    cout<<max_area<<" formed by "<<a[ml]<< " "<<a[mr]<<endl;
}