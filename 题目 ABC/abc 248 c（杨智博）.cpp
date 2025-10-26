#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;

ll dp[55][2505];

int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	
	dp[0][0]=1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
			for(int l=1;l<=m;l++)
				if(j+l<=k) 
				   dp[i+1][j+l]=(dp[i][j]+dp[i+1][j+l])%mod;
	
	ll ans=0;
	for(int i=1;i<=k;i++){  //n~k
		ans+=dp[n][i];
		ans%=mod;
	}
	
	cout<<ans<<endl;
	return 0;
}
