#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
#define pb push_back
using namespace std;

int main() {
    int n = 6;
    int nums[n] = {1,1,3,4,3,2}; //ans 2, 4
    int x = 0;
    rep(i,n) x^=nums[i];
    int d = x&(-x);
    vector<int>a1, a2;
    rep(i,n) {
        if (nums[i]&d) a1.pb(nums[i]);
        else a2.pb(nums[i]); 
    }
    int a=0, b=0;
    rep(i,a1.size()) a^=a1[i];
    rep(i, a2.size()) b^=a2[i];
    cout<<a<<" "<<b<<endl;
}