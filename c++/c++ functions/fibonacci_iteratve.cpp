#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0 ; i<n;i++)
int main() {
    int n;
    cin>>n;
    int prev1=1, prev2=1;
    // for 3 you need to run the loop once so for n it is n-2 times.
    rep(i,n-2) {
        int cur=prev1+prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    cout<<prev1<<endl;
}