#include <bits/stdc++.h>
struct SpareTable{
    vector<vector<int>> st;
    int size;

    int merge(int x,int y){
        return max(x,y);
    }
    SpareTable(vector<int> &a){
        int n = a.size();
        size = log2(n);
        st.resize(n,vector<int>(size+1,0));
        for(int i = 0; i < n; i++) st[i][0] = a[i];
        for(int i=1;(1<<i)<=n;i++){
            for(int j=0;j<=(n-(1<<i));j++){
                st[j][i] = merge(st[j][i-1],st[j+(1<<(i-1))][i-1]);
            }
        }
    }
    //[l,r]
    int query(int l,int r){
        int len = r-l+1;
        int k = log2(len);
        return merge(st[l][k],st[r-(1<<k)+1][k]);
    }
};