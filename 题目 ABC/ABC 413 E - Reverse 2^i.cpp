//ABC 413 E - Reverse 2^i
//https://atcoder.jp/contests/abc413/tasks/abc413_e
//
//https://atcoder.jp/contests/abc413/submissions/67369639

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define rep(i,l,r) for(ll i=l;i<r;++i)
#define yes cout << "Yes\n"
#define no cout << "No\n"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
	int t;
    cin>>t;
    
	rep(ti,0,t){
        int N;
        cin>>N;
        int n = 1<<N;
        vector<int> p(n);
        rep(i,0,n) cin>>p[i];

        for(int w=1;w<=n;w<<=1){
            for(int l=0;l+w*2<=n;l+=w*2){
                if(p[l]>p[l+w]){
                    rep(i,0,w) swap(p[l+i],p[l+w+i]);
                }
            }
        }

        rep(i,0,n) cout << p[i] << ' ';
        cout << '\n';
    }
}

