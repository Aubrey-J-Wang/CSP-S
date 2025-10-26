#include<iostream>
#include<algorithm>
using namespace std;

int n, a[50], cnt_left = 0, cnt_right = 0, ans = -1;
bool considered[1 << 22]; // 1 << n = 2^n.

struct element { // This structure is actually a class in which all members are public.
	int state, total_value;

	element() {}
	element(int x, int y) { state = x, total_value = y; }

	bool operator < (const element& b) const { return total_value < b.total_value; }
	bool operator > (const element& b) const { return total_value > b.total_value; }
} Left[1 << 22], Right[1 << 22]; // Unfortunately, `left' and `right' may cause ambiguity.

// These DFS functions search all possible states and record their information in Left[state] or Right[state].
inline void dfs_left(int x, int total, int state = 0) {
//	Function time complexity: O(3^{N/2}) = O(sqrt{3^n}) which is insignificant.
	if(x > n/2) {
		Left[++cnt_left] = element(state, total);
		return;
	}

	dfs_left(x + 1, total, state); // Not chosen
	dfs_left(x + 1, total + a[x], state bitor (1 << (x - 1))); // Left
	dfs_left(x + 1, total - a[x], state bitor (1 << (x - 1))); // Right
//  state records each compressed state (that is, whether each cow is choosed) with binary.
}

inline void dfs_right(int x, int total, int state = 0) {
//	The two search functions are almost identical.
	if(x > n) {
		Right[++cnt_right] = element(state, total);
		return;
	}

	dfs_right(x + 1, total, state);
	dfs_right(x + 1, total - a[x], state bitor (1 << (x - 1))); // The states are different from the left (in order).
	dfs_right(x + 1, total + a[x], state bitor (1 << (x - 1))); // Though the result does not change.
}

signed main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	dfs_left(1, 0);
	dfs_right(n/2 + 1, 0);
//  We do not search from the destination backwards, but from the middle to the destination,
//	which provides the same results.

	sort(Left + 1, Left + cnt_left + 1, less<element>());
	sort(Right + 1, Right + cnt_right + 1, greater<element>());
//  Sort the Right half in descending order and the Left one in ascending order. In this way, we can search more
//  efficiently. (The right half record the sum oppositely, so we need to sort oppositely.

	for(int i = 1, j = 1; i <= cnt_left and j <= cnt_right; ++i) {
		while(j <= cnt_right and Left[i].total_value + Right[j].total_value > 0)  ++j;
//		If the sum of both sides exceeds 0, the Left half if greater, because the sum on the Right if expressed
//		using negatives; If the sum is 0, the sum on both sides are equal.
//		Hence we get a dividing state.

		for(int pos = j; Left[i].total_value == -Right[pos].total_value; ++pos) {
			int final_state = (Left[i].state bitor Right[pos].state);
//			When we record a legitimate state, put the states on the Left & Right together, resulting in a n-bit number. 
			if(!considered[final_state]) considered[final_state] = true, ++ans;
		}
	}

//	The overall complexity is at most O(2^N), which is all right because n <= 20.
	cout << ans;
	return 0;
}
// Edited and translated by Aubrey Wang