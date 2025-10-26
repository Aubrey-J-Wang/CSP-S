//ABC 213 E - Stronger Takahashi
//01BFS; Similar: ABC 176 D
//https://atcoder.jp/contests/abc213/tasks/abc213_e

#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w;
	cin >> h >> w;
	vector<vector<int> > dist(h, vector<int>(w, INT_MAX));
	string s[h];

	for (string &i : s) cin >> i;

	set<pair<int, pair<int, int> > > pq;
	dist[0][0] = 0;
	pq.insert(make_pair(0, make_pair(0, 0)));

	while (!pq.empty()) {
		pair<int, pair<int, int> > top = *pq.begin();
		pq.erase(pq.begin());
		int d = top.first;
		int i = top.second.first;
		int j = top.second.second;
		if (d > dist[i][j]) continue;
		
		int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
		for (int k = 0; k < 4; ++k) {
			int I = i + di[k];
			int J = j + dj[k];
			if (I >= 0 and I < h and J >= 0 and J < w and s[I][J] == '.' and d < dist[I][J]) {
				dist[I][J] = d;
				pq.insert(make_pair(d, make_pair(I, J)));
			}
		}

		for (int I = i - 2; I <= i + 2; ++I) {
			for (int J = j - 2; J <= j + 2; ++J) {
				if (I < 0 or I >= h or J < 0 or J >= w) continue;
				if (abs(I - i) + abs(J - j) == 4) continue;
				if (I == i and J == j) continue;
				if (s[I][J] == '#' and d + 1 < dist[I][J]) {
					dist[I][J] = d + 1;
					pq.insert(make_pair(d + 1, make_pair(I, J)));
				}
			}
		}
	}

	cout << dist[h - 1][w - 1];
	return 0;
}