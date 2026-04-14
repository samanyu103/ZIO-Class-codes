#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< n; i++)
using namespace std;

int main() {
    string s = "abcbsbsbvhdacx";
    string t = "abcd";
    map<int,int> need;
    rep(i,t.size()) need[t[i]]++;
    int required = need.size();
    map<int, int> have;
    int cnt = 0;
    int n = s.size();
    int j = 0, ans=INT_MAX;
    array<int, 2> ind = {-1,-1};
    rep(i,n) {
        while(j<n) {
            // donot need to expand
            if (cnt==required) break;
            // expand add j
            char c = s[j];
            have[c]++;
            if(need[c] and have[c]==1) cnt++;
            j++;
        }
        // [i..j-1] is valid or j==n,
        if (cnt==required) {
            // [i..j-1] is valid
            if (j-i<ans){
                ans=j-i;
                ind = {i,j-1};
            }
        }
        // shrink left
        char d = s[i];
        have[d]--;
        if (need[d] and have[d]==0) cnt--;
    }
    cout<<ans<<" "<<ind[0]<<" "<<ind[1]<<endl;
}












// need = frequency map of t
// have = empty frequency map
// required = number of unique chars in t
// formed = 0

// right = 0
// minLen = infinity
// ans = (-1, -1)

// for left from 0 to n-1:

//     // Expand right until window becomes valid
//     while right < n AND formed < required:
//         char = s[right]
//         add char to have

//         if char in need AND have[char] == need[char]:
//             formed = formed + 1

//         right = right + 1

//     // Check if current window is valid
//     if formed == required:
//         if (right - left) < minLen:
//             minLen = right - left
//             ans = (left, right - 1)

//     // Before moving left, remove s[left]
//     char = s[left]
//     remove char from have

//     if char in need AND have[char] < need[char]:
//         formed = formed - 1