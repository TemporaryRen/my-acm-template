#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 2e5 + 4;
struct Node{
    int idx;
    int L;
    int R;
}node[MX];
#define L(x) node[x].L
#define R(x) node[x].R
#define idx(x) node[x].idx
int ans[MX];

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int t1,t2;
        cin>>t1>>t2;
        L(i) = t1;
        R(i) = t2;
        idx(i) = i;
    }
    sort(node+1,node+n+1,[](const Node& a,const Node& b){
        if(a.L != b.L) return a.L < b.L;
        else return a.R > b.R;
    });
    stack<pair<int,int>> right;
    right.push({R(1),L(1)});
    ans[idx(1)] = 0;
    forn(i,2,n+1){
        int total = 0;
        int l = 0,r = 1e9 + 5;
        while(!right.empty() && R(i) < right.top().first){
            auto t = right.top();
            if(t.second <= L(i)){
                l = max(t.second,l);
                r = t.first;
            }
            right.pop();
        }
        if(r != 1e9 + 5 && l != 0) ans[idx(i)] = r - R(i) + L(i) - l;
        else ans[idx(i)] = 0;
        right.push({R(i),L(i)});
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    cout<<"\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}