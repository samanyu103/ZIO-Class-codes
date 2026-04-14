#include <bits/stdc++.h>
using namespace std;

bool movie(vector<int>& bills) {
    int fives = 0, tens = 0;

    for (int bill : bills) {
        if (bill == 5) {
            fives++;
        } 
        else if (bill == 10) {
            if (fives == 0) return false;
            fives--;
            tens++;
        } 
        else { // bill == 20
            if (tens > 0 && fives > 0) {
                tens--;
                fives--;
            } 
            else if (fives >= 3) {
                fives -= 3;
            } 
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    
    if (movie(bills)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}