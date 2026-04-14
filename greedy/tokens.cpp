#include <bits/stdc++.h>
using namespace std;

int tokens(vector<int>& a, int P) {
    sort(a.begin(), a.end());

    int left = 0;
    int right = a.size() - 1;
    int score = 0;
    int maxScore = 0;

    while (left <= right) {
        if (P >= a[left]) {
            P -= a[left];
            score++;
            maxScore = max(maxScore, score);
            left++;
        } 
        else if (score > 0) {
            P += a[right];
            score--;
            right--;
        } 
        else {
            break;
        }
    }

    return maxScore;
}

int main() {
    vector<int> a = {100, 200, 300, 400};
    int P = 200;
    cout << tokens(a, P) << endl; // Output: 2
    return 0;
}