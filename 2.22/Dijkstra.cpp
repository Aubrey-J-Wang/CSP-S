#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > gv[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int dist[100001], s[100001];

void add_edge(int u, int v, int x) {
	gv[u].push_back(make_pair(v, x));
}

void dijkstra() {
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	memset(s, 0, sizeof(s));
	dist[1] = 0;
	s[1] = 1;

	pq.push(make_pair(0, 0));

	while (pq.size() != 0) {
		int x = pq.top().second;
		pq.pop();
		if (s[x])
			continue;
		s[x] = true;
		for (int i = 0; i < gv[x].size(); i++) {
			int y = gv[x][i].first, z = gv[x][i].second;
			if (dist[x] + z < dist[y] && !s[y]) {
				dist[y] = dist[x] + z;
				pq.push(make_pair(dist[y], y));
			}
		}
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int v, k, p;
		cin >> v >> k >> p;
		add_edge(v, k, p);
	}

	dijkstra();

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	return 0;
}
