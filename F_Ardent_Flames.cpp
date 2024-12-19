#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 1e5 + 5;
ll h[MX],x[MX];
ll n,m,k;
void solve(){
    cin>>n>>m>>k;
    forn(i,0,n) cin>>h[i];
    forn(i,0,n) {cin>>x[i];x[i]--;}
    ll l = 0LL,r = 1e14 + 5;
    auto check = [](const int ak)->bool {
        for(int i=0;i<n;i++){
            int t = (h[i] + ak - 1) / ak;
            if(t>m) continue;
        }
        map<int,int> cnt;
        return true;
    };
    while(r - l > 1){
        ll mid = (r + l) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout<< (r != 1e14 + 5 ? r : -1)<<"\n";
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