#include<iostream>
using namespace std;

int main() {
    int x = 5;
    cout<<&x;
    int * ptr = &x;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

}