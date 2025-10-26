#include <iostream>
#include <queue>
#define int long long
using namespace std;

int dist[100010], v;

struct NODE {
	int to, next, w;
};

struct QNODE {
	int dis, id;
};

struct cmp {
	bool operator()(QNODE a, QNODE b) {
		return a.dis > b.dis;
	}
};

priority_queue<QNODE, vector<QNODE>, cmp> pq;
NODE edge[500010];
int head[100010];
bool done[100010];

void add_edge(int num, int U, int V, int w) {
	edge[num].to = V;
	edge[num].next = head[U];
	edge[num].w = w;
	head[U] = num;
}

void Dijkstra() {
	while (!pq.empty()) {
		QNODE tmp = pq.top();
		pq.pop();
		
		int ID = tmp.id;
		if(done[ID]) continue;
		done[ID] = true;
		
		for (int i = head[ID]; i; i = edge[i].next) {
			int j = edge[i].to;
			if (dist[ID] + edge[i].w < dist[j] && !done[j]) {
				dist[j] = dist[ID] + edge[i].w;
				pq.push((QNODE) {
					dist[j], j
				});
			}
		}
	}
}

signed main() {
	int e, s;
	cin >> v >> e >> s;

	for (int i = 1; i <= v; i++)
		dist[i] = 1e17;

	for (int i = 1; i <= e; i++) {
		int U, V, w;
		cin >> U >> V >> w;
		add_edge(i, U, V, w);
	}

	pq.push((QNODE) {
		0, s
	});
	dist[s] = 0;

	Dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 1e17)
			cout << 2147483647 << ' ';
		else
			cout << dist[i] << ' ';
	}

	return 0;
}