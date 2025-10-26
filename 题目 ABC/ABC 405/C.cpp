#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

int sum[300005], a[300005];

signed main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	sum[i] = sum[i-1]+a[i];
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += a[i]*(sum[n]-sum[i]);
	}
	cout << ans;
	return 0;
}
