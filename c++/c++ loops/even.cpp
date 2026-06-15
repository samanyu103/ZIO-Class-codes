#include<iostream>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;
    if (x>y) swap(x,y);
    // x<=y always
    if (x%2==1) x++;
    // x is even always
    for(int i = x;i<=y;i+=2) cout<<i<<endl;
}