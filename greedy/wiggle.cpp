#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();

    int up = 1, down = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } 
        else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }

    return max(up, down);
}

int main() {
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout << wiggleMaxLength(nums) << endl; // Output: 6
    return 0;
}