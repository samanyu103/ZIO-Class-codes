#include <bits/stdc++.h>
using namespace std;

int maxTasks(vector<int>& deadlines) {
    sort(deadlines.begin(), deadlines.end());
    
    int time = 0;
    for (int d : deadlines) {
        if (time < d) {
            time++;
        }
    }
    return time;
}

int main() {
    vector<int> deadlines = {1, 2, 2, 3};
    cout << maxTasks(deadlines) << endl; // Output: 3
}