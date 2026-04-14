#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;

    // Process each digit
    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // Remove remaining k digits from top
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Build result (reverse stack)
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    // Remove leading zeros
    int i = 0;
    while (i < result.size() && result[i] == '0') i++;

    result = result.substr(i);

    return result.empty() ? "0" : result;
}

int main() {
    string num = "10200";
    int k = 1;
    cout << removeKdigits(num, k) << endl; // Output: 200
    return 0;
}