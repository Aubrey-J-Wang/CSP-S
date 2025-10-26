#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[1000][600];

struct node {
	int l, r, num, t;
} m[1000];

int cnt;

int dfsmake() {
	cnt++;
	cin >> m[cnt].t;
	int k;
	cin >> k;
	int oo = cnt;
	
	if(k != 0) {
		m[oo].num = k;
		return cnt;
	}
	
	m[oo].l = dfsmake();
	m[oo].r = dfsmake();
	return oo;
}

int check(int pos, int tm) {
	tm -= 2 * m[pos].t;
	
	if(tm < 0)
		return 0;
		
	if(m[pos].num)
		return min(tm / 5, m[pos].num);
		
	int maxv = 0;
	
	for(int i = 0; i <= tm; i++) {
		if(!dp[m[pos].l][i])
			dp[m[pos].l][i] = check(m[pos].l, i);
			
		if(!dp[m[pos].r][tm - i])
			dp[m[pos].r][tm - i] = check(m[pos].r, tm - i);
			
		maxv = max(maxv, dp[m[pos].l][i] + dp[m[pos].r][tm - i]);
	}
	
	return maxv;
}

signed main() {
	int tm;
	cin >> tm;
	tm--;
	dfsmake();
	cout << check(1, tm);
	return 0;
}





