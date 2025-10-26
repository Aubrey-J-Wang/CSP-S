#include <iostream>
#include <vector>
#include <utility>
#include <optional>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string opts = "URDL";
	i64 dx[] = {-1, 0, 1, 0};
	i64 dy[] = {0, 1, 0, -1};
	
	i64 Rt, Ct, Ra, Ca;
	cin >> Rt >> Ct >> Ra >> Ca;
	
	i64 N, M, L;
	cin >> N >> M >> L;
	
	vector<pair<char, i64>> s(M);
	vector<pair<char, i64>> t(L);
	
	for (auto& [_i, j] : s) cin >> _i >> j;
	
	for (auto& [_i, j] : t) cin >> _i >> j;
	
	int p1 = 0, p2 = 0;
	i64 ans = 0;
	while (p1 < M && p2 < L) {
		int op1 = opts.find(s[p1].first);
		int op2 = opts.find(t[p2].first);
		i64 k = min(s[p1].second, t[p2].second);
		
		// Some calculation
		optional<i64> t1;
		bool ok1 = false;
		i64 r_diff = Ra - Rt;
		i64 dr_diff = dx[op1] - dx[op2];
		if (r_diff == 0) {
			if (dr_diff == 0) ok1 = true;
			else t1 = 0;
		} else {
			if (dr_diff != 0 && r_diff % dr_diff == 0) t1 = r_diff / dr_diff;
		}
		
		optional<i64> t2;
		bool ok2 = false;
		i64 c_diff = Ca - Ct, dc_diff = dy[op1] - dy[op2];
		if (c_diff == 0) {
			if (dc_diff == 0) ok2 = true;
			else t2 = 0;
		} else {
			if (dc_diff != 0 && c_diff % dc_diff == 0) {
				t2 = c_diff / dc_diff;
			}
		}
		
		// Correct ones
		if (ok1 && ok2) {
			// Completely synchronise
			ans += k;
		} else {
			// Find meeting point
			i64 final_t = -1;
			if (ok1) { // Only y sync
				if (t2.has_value()) final_t = t2.value();
			} else if (ok2) { // Only x sync
				if (t1.has_value()) final_t = t1.value();
			} else { // Neither
				if (t1.has_value() && t2.has_value() && t1.value() == t2.value()) {
					final_t = t1.value();
				}
			}
			
			if (final_t > 0 && final_t <= k) {
				ans++; // Met
			}
		}
		
		s[p1].second -= k;
		if (s[p1].second == 0) p1++;
		t[p2].second -= k;
		if (t[p2].second == 0) p2++;
		
		Rt += dx[op1] * k, Ra += dx[op2] * k;
		Ct += dy[op1] * k, Ca += dy[op2] * k;
	}
	cout << ans << "\n";
	return 0;
}

