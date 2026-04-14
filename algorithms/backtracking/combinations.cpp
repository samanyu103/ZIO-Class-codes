#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& a, int n, int k, int start,vector<int>& curr, vector<vector<int>>& result) {
    
    // pruning: not enough elements left
    // a[0..start-1] is explored and in curr. remaning elements n-start
    if (n - start < k - curr.size())
        return;

    if (curr.size() == k) {
        result.push_back(curr);
        return;
    }

    for (int i = start; i < n; i++) {
        curr.push_back(a[i]);                 // choose
        backtrack(a, n, k, i + 1, curr, result); // explore
        curr.pop_back();                      // backtrack
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    int n = a.size();
    int k = 2;

    vector<vector<int>> result;
    vector<int> curr;

    backtrack(a, n, k, 0, curr, result);

    // print result
    for (auto& comb : result) {
        for (int x : comb) cout << x << " ";
        cout << endl;
    }

    return 0;
}