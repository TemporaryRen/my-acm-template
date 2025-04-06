#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()

int N,M;
const int MX = 2e5 + 5;
struct Node{
    int L,R,pos;
    bool operator < (const Node b) const{return L < b.L;};
}nodes[MX << 1];

int st[MX<<1][32];

int result[MX];

void build(){
    int next = 0;
    forn(i,0,N*2){
        while(next < N*2 && nodes[next].L <= nodes[i].R){
            next++;
        }
        st[i][0] = next - 1;
    }
    forn(k,1,32){
        forn(i,0,N*2){
            st[i][k] = st[st[i][k-1]][k-1];
        }
    }
}

int answer(){
    forn(i,0,N){
        int ans = 0;
        int end = nodes[i].L + M;
        int curr = i;
        for(int k=log2(N)+1;k>=0;k--){
            if(nodes[st[curr][k]].R <= end){
                ans += 1 << k;
                curr = st[i][k];
            }
        }
        result[nodes[i].pos] = ans + 1;
    }
}

void solve(){
    cin>>N>>M;
    forn(i,0,N){
        cin>>nodes[i].L>>nodes[i].R;
        if(nodes[i].R < nodes[i].L) nodes[i].R += M;
        nodes[i].pos = i;
    }
    // 排序
    sort(nodes,nodes+N);
    forn(i,N,N*2){
        nodes[i].L = nodes[i-N].L + M;
        nodes[i].R = nodes[i-N].R + M;
        nodes[i].pos = nodes[i-N].pos;
    }
    //build st
    answer();
    forn(i,0,N) cout<<result[i]<<"\n";

    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}