#include <iostream>
#include <queue>
using namespace std;

int n, m;

struct edge {
	int to;
	int next;
} e[501];

int cnt = 1;
int head[101];
bool vis[101];

void add_edge(int u, int v) { //u=1  v=5
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
	++cnt;
}

void dfs(int k) { //k=V1
	vis[k] = true;
	cout << k << ' ';

	for (int i = head[k]; i; i = e[i].next) //k=1
		if (!vis[e[i].to])
			dfs(e[i].to);
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = true;

	while (!q.empty()) {
		int now = q.front();
		cout << now << ' ';
		q.pop();
		for (int i = head[now]; i; i = e[i].next)
			if (!vis[e[i].to]) {
				q.push(e[i].to);
				vis[e[i].to] = true;
			}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		add_edge(x, y);
	}

	for (int i = 1; i <= n; ++i)
		vis[i] = false;

	dfs(1);
	cout << endl;

	for (int i = 1; i <= n; ++i)
		vis[i] = false;

	bfs(1);
	cout << endl;

	return 0;
}
