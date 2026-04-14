#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

void increment(int x) {
    x++;
}


int main() {
    int x = 1;
    increment(x);
    cout<<x<<endl;
}