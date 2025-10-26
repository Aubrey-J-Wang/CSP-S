//Âå¹ÈP1828£¬ Sweet Butter
//https://www.luogu.com.cn/problem/P1828 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll at[5005],e[8005][8005];

int main() {
	ll n,p,c,x,y,z,sum=1e10;
	cin >> n >> p >> c;
	for (ll i=1; i<=n; i++) {
		cin >> at[i];
	}
	for (ll i=1; i<=p; i++) {
		fill(e[i]+1,e[i]+p+1,1e10);
		e[i][i]=0;
	}
	for (ll i=1; i<=c; i++) {
		cin >> x>> y>>z;
		e[x][y]=e[y][x]=z;
	}


	for (ll k=1; k<=p; k++) {
		for (ll i=1; i<=p; i++) {
			for (ll j=i; j<=p; j++) {
				e[i][j]=e[j][i]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	
	for (ll i=1; i<=p; i++) {
		ll ans=0;
		for (ll j=1; j<=n; j++) {
				ans+=e[at[j]][i];
			
		}
//		cout << ans << " ";
		sum=min(sum,ans);
	}
	cout << sum << endl;
	return 0;
}


