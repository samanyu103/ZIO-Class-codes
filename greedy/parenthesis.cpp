#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int lo = 0, hi = 0;

    for (char c : s) {
        if (c == '(') {
            lo++;
            hi++;
        } 
        else if (c == ')') {
            lo--;
            hi--;
        } 
        else { // '*'
            lo--;      // treat as ')'
            hi++;      // or treat as '('
        }

        if (hi < 0) return false;
        lo = max(lo, 0);
    }

    return lo == 0;
}

int main() {
    string s = "(*))";
    cout << (checkValidString(s) ? "true" : "false") << endl; // Output: true
    return 0;
}