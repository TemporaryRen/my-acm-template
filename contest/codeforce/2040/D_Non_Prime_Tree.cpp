#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector g(n,vector<int>());
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector ans(n,1);
    vector vis(n,false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    vector used(n*2+1,false);
    vector fast(n*2+1,1);
    for(int i=1;i<n*2+1;i++) fast[i] = i+1;
    used[1] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i<g[t].size();i++){
            if(vis[g[t][i]]) continue;
            int x = ans[t],y = fast[x];
            while(used[y]){
                if(y-x==1) y=x+4;
                else y += 2;
            }
            fast[x] = y;
            used[y] = true;
            ans[g[t][i]] = y;
            q.push(g[t][i]);
            vis[g[t][i]] = true;
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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