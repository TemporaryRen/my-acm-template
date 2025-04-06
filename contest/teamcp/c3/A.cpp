#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()

const int MX = 1e9 + 7;

void solve(){
    int n;cin>>n;
    int L = 0,R = MX;
    vector<int> e;
    while(n--){
        int x,y;cin>>x>>y;
        if(x == 1){
            L = max(L,y);
        }else if(x == 2){
            R = min(y,R);
        }else{
            e.push_back(y);
        }
    }
    int ans = R - L + 1;
    for(auto x : e){
        if(x >= L && x <= R) ans --;
    }
    cout<<max(ans,0)<<"\n";

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