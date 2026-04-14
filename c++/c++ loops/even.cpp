#include<iostream>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;
    if (x>y) swap(x,y);
    if (x%2==1) x++;
    for(int i = x;i<=y;i+=2) cout<<i<<endl;
}