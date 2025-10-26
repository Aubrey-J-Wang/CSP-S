#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, q;
	cin >> m >> q;
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	while(q--){
		int b, k;
		cin >> b >> k;
		
		auto f = [&](int x) -> bool{
			auto lb = lower_bound(a.begin(), a.end(), b-x);
			auto ub = upper_bound(a.begin(), a.end(), b+x);
			return ub-lb >= k;
		};
		
		int left = -1, right = (int) 2e8+10;
		while(right-left > 1){
			int mid = (left+right) / 2;
			if(f(mid)) right = mid;
			else left = mid;
		}
		cout << right << endl;
	}
	return 0;
}
