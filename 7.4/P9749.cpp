#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
	int n, d;
	cin >> n >> d;
	vector<int> v(n, 0), a(n, 0);
	for(int i = 1; i < n; i++) cin >> v[i];
	int money = (1 << 31)-1;
	int ans = 0, s = 0;
//	If s < 0, |s| denotes the length that the car can still go. Otherwise, it denotes that the petrol tank is empty.
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		s += v[i];
		money = min(money, a[i]);
		if(s > 0) {
			ans += (s + d - 1) / d * money; // This rather strange calculation can find ceil(s/d)*money.
			s -= (s + d - 1) / d * d;
		}
	}
	cout << ans;
	return 0;
}