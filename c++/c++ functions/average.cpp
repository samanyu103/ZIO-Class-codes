#include<iostream>
using namespace std;
double average(int a, int b) {
    return (a+b)/2.0;//note if we used 2 then it would perform integer division.
}
int main() {
    int x,y;
    cin>>x>>y;
    cout<<average(x,y)<<endl;
}