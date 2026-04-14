#include<iostream>
using namespace std;

int main() {
    int x, y;
    cout<<"Number 1: ";
    cin>>x;
    cout<<"Number 2: ";
    cin>>y;   
    char op;
    cout<<"operator: ";    
    cin>>op;
    cout<<"Result: ";
    if (op=='+') cout<<x+y<<endl;
    else if (op=='-') cout<<x-y<<endl;
    else if (op=='*') cout<<x*y<<endl;
    else if (op=='/') cout<<x/y<<endl;
    else cout<<"Invalid operand"<<endl;

}