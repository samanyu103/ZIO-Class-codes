#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) nums.push_back(i);

    vector<int> fact(n, 1);
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;

    k--; // convert to 0-based index

    string ans = "";
    for (int i = n; i >= 1; i--) {
        int idx = k / fact[i - 1];
        ans += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= fact[i - 1];
    }

    return ans;
}

int main() {
    int n = 3, k = 3;
    cout << getPermutation(n, k) << endl;
    return 0;
}