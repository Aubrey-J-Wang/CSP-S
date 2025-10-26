#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

vector<int> a(300005), sum(300005);

signed main(){
	int n, q;
	cin >> n >> q;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(), a.begin()+n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i-1];
	while(q--){
		int b;
		cin >> b;
		int pos = lower_bound(a.begin(), a.begin()+n, b) - a.begin();
//		cout << pos << ' ' << sum[pos] << ' ';
		if(sum[pos] + (b-1)*(n-pos) >= sum[n]) cout << -1 << endl;
		else if(sum[pos] + (b-1)*(n-pos) + 1 < b) cout << b << endl;
		else cout << sum[pos] + (b-1)*(n-pos) + 1 << endl;
	}
	return 0;
}
