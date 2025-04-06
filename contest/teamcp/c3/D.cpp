#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    string s,t;cin>>s>>t;
    map<char,int> pos;
    for(int i=0;i<t.size()-1;i++){
        pos[t[i]] = i;
    }
    int l = s.size(),r=-1;
    for(int i=1;i<s.size();i++){
        if(pos.find(s[i]) != pos.end()){
            int j = pos[s[i]];
            if(i-j < l-r){
                l = i;
                r = j;
            }
        }
    }
    if(l == s.size() || r == -1){
        cout<<-1;
    }else{
        cout<<(s.substr(0,l) + t.substr(r,t.size()-r));
    }
    cout<<"\n";
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