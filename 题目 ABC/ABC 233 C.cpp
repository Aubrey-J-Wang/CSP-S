//ABC 233 C - Product
//https://atcoder.jp/contests/abc233/tasks/abc233_c

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n, x, ans = 0;
vector<vector<ll> > a;

void dfs(ll pos, ll prod){
	if(pos == n){
		if(prod == x) ans++;
		return;
	}
	
	for(auto c : a[pos]){
		if(prod > x/c or x%c != 0) continue;
		dfs(pos+1, prod*c);
	}
}

int main() {
    ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

    cin >> n >> x;
    a.resize(n);
    
    for(ll i = 0; i < n; i++){
    	ll L;
    	cin >> L;
    	a[i].resize(L);
    	for(int j = 0; j <= L-1; j++) cin >> a[i][j];
	}
	
	dfs(0, 1);
	cout << ans;
	return 0;
}
