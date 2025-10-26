//ABC 213 E - Stronger Takahashi
//01BFS; 类似的题目：ABC 176 D
//https://atcoder.jp/contests/abc213/tasks/abc213_e

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int dx[] = {2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2};
int dy[] = {-1, 0, 1, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -1, 0, 1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	char grid[n + 2][m + 2];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> grid[i][j];

	int dist[n + 5][m + 5];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = 1e9;

	dist[1][1] = 0;

	priority_queue<vector<int> > q;
	q.push({0, 1, 1});

	while (q.size()) {
		int i = q.top()[1], j = q.top()[2];
		q.pop();

		for (int k = 0; k < 20; k++) {
			int ci = i + dx[k];
			int cj = j + dy[k];
			if (ci < 1 || cj < 1 || ci > n || cj > m)
				continue;

			int cost = grid[ci][cj] == '.' and abs(i - ci) + abs(j - cj) <= 1 ? 0 : 1;

			if (dist[ci][cj] > dist[i][j] + cost) {
				dist[ci][cj] = dist[i][j] + cost;
				q.push({-dist[ci][cj], ci, cj});
			}
		}
	}

	cout << dist[n][m];
	return 0;
}