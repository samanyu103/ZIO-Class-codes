#include <bits/stdc++.h>
using namespace std;

int minmoves(vector<int>& nums, int t) {
    int miss = 1;  // smallest missing sum
    int moves = 0;
    int i = 0;
    int n = nums.size();

    while (miss <= t) {
        if (i < n && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            // patch with 'miss'
            miss += miss;
            moves++;
        }
    }

    return moves;
}

int main() {
    vector<int> nums = {1, 3};
    int n = 7;
    cout << minmoves(nums, n) << endl; // Output: 2
    return 0;
}