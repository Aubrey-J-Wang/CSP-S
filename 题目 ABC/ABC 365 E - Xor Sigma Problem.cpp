//ABC 365 E - Xor Sigma Problem
//https://atcoder.jp/contests/abc365/tasks/abc365_e
//
//https://atcoder.jp/contests/abc365/submissions/56325014

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[200055],p[200055],sum[200055],ans,s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;

	for(int i=1;i<=n;i++) 
	   cin>>a[i],s+=a[i];

	for(int k=0;k<=31;k++){
		for(int i=1;i<=n;i++){
			if((a[i]>>k)&1) p[i]=1;
			else p[i]=0;
			sum[i]=sum[i-1]^p[i];
		}
		int b[2]={1,0},cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=b[!sum[i]];
			b[sum[i]]++;
		}
		ans+=cnt*(1<<k);
	}
	
	cout<<ans-s<<endl;
	return 0;
}

