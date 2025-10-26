#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>

#define int long long
#define First first.first
#define Second first.second
#define Third second

using namespace std;
int n, length_left, gx, gy;

struct move {
	int x, y;
} a[45];

int ans[45], all[21];
vector<pair<pair<int, int>, int> > Left, Right, current;

signed main() { // O(n^3)
	cin >> n >> gx >> gy;
	for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	length_left = n / 2;
	Left.push_back({0, {0, 0}});
	
	for(int i = 1; i <= length_left; i++) {
//		Search the left.
		current.clear(); // Current is a temporary array used to store the current.
		for (auto p : Left)
			current.push_back({{p.First + a[i].x, p.Second + a[i].y}, p.Third + 1});
		for (auto p : current) Left.push_back(p);
	}
	
	Right.push_back({{gx, gy}, 0});
	for(int i = length_left + 1; i <= n; i++) {
		current.clear();
		for (auto p : Right)
			current.push_back({{p.First - a[i].x, p.Second - a[i].y}, p.Third + 1});
		for (auto p : current) Right.push_back(p);
	}
//	Right

	sort(Left.begin(), Left.end());
	sort(Right.begin(), Right.end());
	auto last = {1e18, 1e18};
	int pos = 0;
	
	for (auto p : Left) {
		if (p.first != last) {
			memset(all, 0, sizeof all);
			while (pos < Right.size() and Right[pos].first < p.first) pos++;
			for (pos; pos < Right.size() and Right[pos].first == p.first; pos++)
				all[Right[pos].second]++; //Two ptrs
		}
		for(int i = 0; i <= 20; i++) ans[i + p.second] += all[i];
		last = p.first;
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}