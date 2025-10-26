#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
template<class T, class U> inline bool chmin(T& a, const U& b) {
	if(a > b) {
		a = b;
		return true;
	} return false;
}

int main() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> dp(m, inf);
	dp[0] = 0;
	
	for(int i = 0; i < l; i++) {
		vector<int> ep(m, inf);
		
		for(int j = 0; j < m; j++) {
			int cost = 0;
			
			for(int k = i; k < n; k += l) {
				if(j >= a[k]) cost += j - a[k];
				else cost += j - a[k] + m;
			}
			
			for(int k = 0; k < m; k++) chmin(ep[(k + j) % m], dp[k] + cost);
		}
		
		dp = move(ep);
	}
	
	cout << dp[0] << '\n';
}

