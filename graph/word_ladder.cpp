#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define rep(i,n) for(int i=0; i<n;i++)

string begin_word, end_word;
vector<string> word_list;
map<string, int> m;
// inverse map
map<int, string> m_;
const int N = 1e5+5;
int d[N];
int n;


void bfs() {
    queue<int> q;
    rep(i,n+1) d[i] = INT_MAX;
    q.push(m[begin_word]);
    d[m[begin_word]]=0;
    // rep(i,n) cout<<d[i]<<endl;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        string w = m_[u];
        int l = w.size();
        rep(i,l) {
            rep(j,26) {
                string new_w = w;
                new_w[i]= 'a'+j;
                int v = m[new_w];
                if(v and d[v] == INT_MAX) {
                    d[v] = d[u]+1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    cin>>begin_word>>end_word;
    cin>>n;
    rep(i,n) {
        string s;
        cin>>s;
        word_list.pb(s);
        m[s]=i+1;
        m_[i+1]=s;
    }
    // cout<<begin_word<<end_word;
    // cout<<n<<endl;
    cout<<m[end_word]<<endl;
    // rep(i,n) cout<<word_list[i]<<endl;
    bfs();
    int ans = d[m[end_word]];
    if (ans==INT_MAX) ans=-1;
    cout<<ans<<endl;    
}