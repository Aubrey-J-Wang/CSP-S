#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace editorial {
//	The time complexity is given in the editorial.
	void solve() {
		int N;
		cin >> N;
		vector<int> S(N);
		for (auto& a : S) cin >> a;

		vector<int> used(N);
		int ans = 1, last = 0;
		while (true) {
			if (S[last] * 2 >= S[N - 1]) {
				ans++;
				break;
			}
			int nxt = -1;
			for (int i = 1; i <= N - 1; i++) {
				if (used[i]) continue;
				if (S[last] * 2 >= S[i]) {
					if (nxt != -1 && S[nxt] >= S[i]) continue;
					nxt = i;
				}
			}
			if (nxt == -1 || S[nxt] <= S[last]) {
				cout << -1 << endl;
				return;
			}
			ans++, last = nxt, used[nxt] = 1;
		}
		cout << ans << endl;
	}
}

namespace self{
//	Time complexity: O(sum: N log sum: N)
	void solve(){
		int N;
		cin >> N;
		int s[N];
		for(int& i : s) cin >> i;
		
		sort(s+1, s+N-1);
		int ans = 1;
		for(int i = 0; i < N-1; ){
			if(s[N-1] <= s[i]*2){
				ans++;
				break;
			}
			auto it = upper_bound(s+1, s+N-1, s[i]*2)-1;
			if(it-s-i < 1){
				cout << -1 << endl;
				return;
			}else i += it-s-i;
			ans++;
		}
		cout << ans << endl;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) editorial::solve();
//	Note: Both solutions are correct and the time complexity is similar.
	return 0;
}
