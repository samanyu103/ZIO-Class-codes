#include<bits/stdc++.h>
using namespace std;
// typedef int in;
// #define int long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,n) for(int i = 0; i < n; i++)
// n is the number of rows, m is the number of columns
int n, m;

// get point number from coordinate
int p(int x, int y) {
    return x*m+y;
}
// get coordinate from point number
array<int,2> c(int x) {
    return {x/m, x%m};
}

bool adjacent (array<int,2> x, array<int,2> y) {
    // translate to 0
    y[0]-=x[0];
    y[1]-=x[1];
    // if gcd is 1 or -1 then there will be no lattice point in between (0,0) and (y[0], y[1])
    // if gcd not equal to 1 then there will be some lattice point between them thus non adjacent.
    int g = __gcd(y[0], y[1]);
    return  (g == 1 or g == -1);

}

void solve() {

    cin>>n>>m;
    int N = n*m;
    // dp[mask][last]
    // mask: 0 if unvisited, 1 if visited.
    // for example dp[01001][1] is the number of ways to visit cells 1 and 4 with 1 being the last cell visited.
    // in dp[mask][j], if the jth bit in mask is 0 then clearly dp[mask][j]=0
    // to transition back from say dp[01001][1], we first unset the j the bit in mask, that is mask becomes 00001
    // then we iterate over set bits jj and see if we have a valid transition from jj to j.
    // subsequently we will add dp[00001][4] to dp[01001][1].
    // valid transitions are represented by adj[jj][j] = 1.
    int dp[1<<N][N]={};
    // adjacency matrix: 0,0 is not adjacent to 2,0 since 1,0 comes in between.
    int adj[N][N];
    rep(i,N) {
        rep(j,N) {
            adj[i][j] = adjacent(c(i),c(j));
        }
    }

    // cout<<"Adjacency Matrix\n";
    // cout<<"  ";
    // rep(j,N) cout<<j<< " ";
    // cout<<endl;
    // rep(i,N) {
    //     cout<<i<< " ";
    //     rep(j,N) {
    //         cout<<adj[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    rep(i, 1<<N) {
        rep(j,N) {
            // jth bit is 0 in i
            if ((i>>j)&1 == 0) {
                dp[i][j]=0;
            }else{
                // unset the jth bit
                int ii = i ^ (1<<j);
                // only 1 set bit in the mask i.
                if (ii == 0) {
                    dp[i][j] =1;
                }
                else{
                    rep(jj,N) {
                        // jj th bit is set in ii
                        if ((ii>>jj)&1) {
                            // note that jj cannot be = j here since the jth bit is 0 in ii.
                            // valid transition from jj to j.
                            if (adj[jj][j]) {
                                dp[i][j]+=dp[ii][jj];
                            }
                        }
                    }
                }
            }
        }
    }
    // cout << "DP\n";
    // cout<<"  ";
    // rep(j,n) cout<<j<<" ";
    // cout<<endl;
    // rep(i,1<<n) {
    //     cout<<i<< " ";
    //     rep(j,n) {
    //         cout<<dp[i][j]<<" ";
    //         // ans+=dp[i][j];
    //     }
    //     cout<<endl;
    // }

    // to get the answer you chose a mask of visited cells and a last visited cell and add everything up 
    int ans = 0;
    rep(i,1<<N) {
        rep(j,N) {
            ans+=dp[i][j];
        }
    }
    // masks with only one bit set like 00001000000, donot count it as there is no edge.
    // there are N numbers with a single set bit.
    ans-=N;
    cout<<ans<<endl;

}
int main() {
    int tt=1;
    cin>>tt;
    while(tt--) {
        solve();
    }
}