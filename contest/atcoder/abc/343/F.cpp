#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define ls(x) x<<1
#define rs(x) (x<<1)|1

const int MX = 2e5 + 5;
int N;
struct Node{
    int mmax,smax,mcnt,scnt;
    void operator=(const int i){
        mmax = i;
        smax = -1;
        mcnt  = 1;
        scnt = 0;
    }
}nodes[MX << 2];
int a[MX];

inline void combine(Node& res,const int x,const int y){
    if(x > res.mmax){
        res.scnt = res.mcnt;
        res.smax = res.mmax;
        res.mmax = x;
        res.mcnt = y;
    }else if(x == res.mmax) res.mcnt += y;
    else if(x > res.smax){
        res.scnt = y;
        res.smax = x;
    }else if(x == res.smax) res.scnt += y;
}

Node operator+(const Node& l, const Node& r){
    Node res{};
    res.mcnt = l.mcnt;
    res.mmax = l.mmax;
    res.scnt = l.scnt;
    res.smax = l.smax;
    combine(res,r.mmax,r.mcnt);
    combine(res,r.smax,r.scnt);
    return res;
}

inline void pushUp(const int curr){
    nodes[curr] = nodes[ls(curr)] + nodes[rs(curr)];
}

inline void build(const int curr = 1,const int l = 1,const int r = N){
    if(l == r) nodes[curr] = a[l];
    else{
        const int mid = (l + r) >> 1;
        build(ls(curr),l,mid);
        build(rs(curr),mid + 1,r);
        pushUp(curr);
    }
}

inline void update(const int curr,const int l,const int r,const int p,const int v){
    if(l == r) nodes[curr] = v;
    else{
        const int mid = (l + r) >> 1;
        if(p <= mid) update(ls(curr),l,mid,p,v);
        else update(rs(curr),mid+1,r,p,v);
        pushUp(curr);
    }
}

inline Node query(const int curr,const int l,const int r,const int L,const int R){
    if(L<=l && R>=r) return nodes[curr];
    else{
        const int mid = (l + r) >> 1;
        if(L>mid) return query(rs(curr),mid+1,r,L,R);
        if(R<=mid) return query(ls(curr),l,mid,L,R);
        return query(rs(curr),mid+1,r,L,R) + query(ls(curr),l,mid,L,R);
    }
}



void solve(){
    int Q;cin>>N>>Q;
    forn(i,1,N+1) cin>>a[i];
    build();
    while(Q--) {
        int type,x,y;
        cin>>type>>x>>y;
        if(type == 1) update(1,1,N,x,y);
        else{
            Node ans = query(1,1,N,x,y);
            cout<<ans.scnt<<"\n";
        }
    }
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