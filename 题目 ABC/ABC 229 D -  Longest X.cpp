//ABC 229 D -  Longest X
//https://atcoder.jp/contests/abc229/tasks/abc229_d
//https://atcoder.jp/contests/abc229/editorial/2984

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main(){
    string s;
	cin>>s;
    ll k;
	cin>>k;
    ll n=s.size();

    vector<ll>  cnt(n+1); // cumulative sums
    
	for(ll i=0;i<=n-1;i++){
        if(s[i]=='.')
		   cnt[i+1] = cnt[i] + 1;
        else 
		   cnt[i+1] = cnt[i];
    }
	// cnt[r]-cnt[l] represents the number 
	// of '.' in s[l,r)

    ll ans = 0;
    ll r = 0;
    
	for(ll l=0;l<=n-1;l++){  //r=9    L=5
        while(r<=n-1 && cnt[r+1]-cnt[l] <= k){
            r = r+1;
        }
        ans = max(ans,r-l);
    }
    
	cout<<ans<<endl;
    return 0;
}


