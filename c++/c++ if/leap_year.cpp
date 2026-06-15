#include<iostream>
using namespace std;

int main() {
    int x;
    cin>>x;
    if (x%4==0) {
        // divisible by 4
        if (x%100==0) {
            // divisible by 100
            if(x%400==0) cout<<"Yes\n"; // divisible by 400
            else cout<<"No\n"; //not divisible by 400 but divisible by 100
        }else cout<<"Yes\n"; // divisible by 4 but not by 100
    }
    // not divisible by 4
    else cout<<"No\n";
}

// x%4==0 and (x%100!=0 or x%400==0)