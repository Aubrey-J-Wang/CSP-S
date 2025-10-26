#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define int long long
using namespace std;
const int MAXN = 100005;

struct node {
	int from, to, cost, left, d, k;
};

vector<node> a[MAXN], b[MAXN];
int ans[MAXN];
bool visited[MAXN];

priority_queue<pair<int, int> > q;

void dijkstra(int start) {
	ans[start] = 2e18;
	q.push({ans[start], start});

	while(!q.empty()) {
		int k = q.top().second;
		q.pop();

		if(visited[k]) {
			continue;
		}

		visited[k] = true;

		for(auto i : a[k]) {
			int to = i.to, cost = i.cost, left = i.left, k1 = i.k, d = i.d;

			if(ans[k] - cost < left) {
				continue;    // If we can never arrive...
			}

			int now = min(k1 - 1, (ans[k] - cost - left) / d) * d + left;

			if(ans[to] < now) {
				ans[to] = now;
				q.push({ans[to], to});
			}
		}
	}
}

signed main() {
	int N, M;
	cin >> N >> M;

	for(int i = 1; i <= M; i++) {
		node t;
		cin >> t.left >> t.d >> t.k >> t.cost >> t.from >> t.to;
		swap(t.from, t.to);
		a[t.from].push_back(t);
	}

	dijkstra(N);

	for(int i = 1; i < N; i++) {
		if(!ans[i]) {
			cout << "Unreachable" << endl;
		}
		else {
			cout << ans[i] << endl;
		}
	}

	return 0;
}

