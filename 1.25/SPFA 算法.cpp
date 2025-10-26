#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 2333333;

struct edge {
	int to;
	int w;
	int next;
} edges[maxn];

int head[maxn], dis[maxn], cnt;
int n, m, s;
bool inque[maxn];
queue<int> Q;

inline void add(int u, int v, int w) {
	cnt++;
	edges[cnt].to = v;
	edges[cnt].w = w;
	edges[cnt].next = head[u];
	head[u] = cnt;
}

inline void spfa() {
	memset(dis, 0x7f, sizeof(dis));
	Q.push(s);
	dis[s] = 0;
	inque[s] = true;

	int u, v;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		inque[u] = false;

		for (int i = head[u]; i != 0; i = edges[i].next) {
			v = edges[i].to;
			if (dis[u] + edges[i].w < dis[v]) {
				dis[v] = dis[u] + edges[i].w;
				if (!inque[v]) {
					inque[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

int main() {
	int u, v, w;

	cin >> n >> m >> s;

	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
	}

	spfa();

	for (int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}

	return 0;
}

