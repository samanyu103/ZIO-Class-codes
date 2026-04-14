#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;


int sos(int n) {
    int ans = 0;
    while(n) {
        int d = n%10;
        ans+=d*d;
        n/=10;
    }
    return ans;
}

int f(int n ) {
    cout<<n<<" ";
    set<int>s;
    int cnt = 0;
    bool cycle=0;
    while(n!=1) {
        if (s.find(n)!=s.end()) {
            cout<<"cycle ";
            cycle=1;
            break;
        }
        s.insert(n);
        n=sos(n);
        cnt++;
    }
    cout<<cnt<<endl;
    return cnt;  
}

bool good(int n ) {
    // cout<<n<<" ";
    set<int>s;
    // int cnt = 0;
    // bool cycle=0;
    while(n!=1) {
        if (s.find(n)!=s.end()) {
            // cout<<"cycle ";
            // cycle=1;
            return 0;
            // break;
        }
        s.insert(n);
        n=sos(n);
        // cnt++;
    }
    // cout<<cnt<<endl;
    return 1;  
}


int main() {
    // for(int i = 1 ; i <100 ; i++) f(i);
    // for(int i = 1 ; i <100 ; i++) cout<<i<<" "<<good(i)<<endl;;
    int n;
    cin>>n;
    cout<<(good(n)?"good":"bad")<<endl;

}