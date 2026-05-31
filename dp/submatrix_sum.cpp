#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)


int countSubmatrices(vector<vector<int>>& a, int k) {
    int n = a.size(), m = a[0].size();
    int ans = 0;

    for(int top = 0; top < n; top++) {
        vector<int> col(m, 0);

        for(int bottom = top; bottom < n; bottom++) {

            // compress rows into 1D
            for(int j = 0; j < m; j++) {
                col[j] += a[bottom][j];
            }

            // now solve 1D problem
            unordered_map<int,int> mp;
            mp[0] = 1;

            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += col[j];

                if(mp.count(sum - k))
                    ans += mp[sum - k];

                mp[sum]++;
            }
        }
    }

    return ans;
}



int main() {
    vector<vector<int>> a = {
        {1, 2, 1},
        {2, 3, 1},
        {1, 1, 1}
    };

    int k = 4;

    int result = countSubmatrices(a, k);

    cout << "Number of submatrices with sum = " << k << " is: ";
    cout << result << endl;

    return 0;
}