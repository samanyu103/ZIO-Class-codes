#include <bits/stdc++.h>
using namespace std;

int maxSatisfiedStudents(vector<int>& need, vector<int>& capacity) {
    sort(need.begin(), need.end());
    sort(capacity.begin(), capacity.end());

    int i = 0; // pointer for students
    int j = 0; // pointer for backpacks

    int n = need.size();
    int m = capacity.size();

    int satisfied = 0;

    while (i < n && j < m) {
        if (capacity[j] >= need[i]) {
            // assign backpack j to student i
            satisfied++;
            i++;
            j++;
        } else {
            // backpack too small, try next bigger one
            j++;
        }
    }

    return satisfied;
}

int main() {
    vector<int> need = {2, 4, 5};
    vector<int> capacity = {3, 3};

    cout << maxSatisfiedStudents(need, capacity) << endl; // Output: 1
    return 0;
}