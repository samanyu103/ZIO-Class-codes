#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)


int sum(int a,int b) {
    cout<<"first ";
    return a+b;
}
int sum(int a, int b, int c) {
    cout<<"second ";
    return a+b+c;
}
double sum(double a, double b){
    cout<<"third ";
    return a+b;
}
int main() {
    sum(3,5);
    sum(3,5,6);
    // sum(3.0, 5); ambiguous
    sum(3.0, 5.0);
}