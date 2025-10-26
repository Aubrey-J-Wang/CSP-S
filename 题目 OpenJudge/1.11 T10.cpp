#include<bits/stdc++.h>
using namespace std;
int d[50010], L, n, m;
bool check(int dis, int n, int m){
	int last = 0, s = 0;
	for(int i = 1; i <= n; i++){
		if(d[i]-last >= dis) last = d[i];
		else s++;
	}
	return s <= m;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> L >> n >> m;
	for(int i = 1; i <= n; i++) cin >> d[i];
	d[n+1] = L;
	int l = 0, r = L-1, mid = 0, ans = 0;
	while(l <= r){
		mid = (l+r)/2;
		if(check(mid, n+1, m)){
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	cout << ans;
	return 0;
}