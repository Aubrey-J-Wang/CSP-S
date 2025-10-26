#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int N = 10010, M = 105;

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9') {
		if(c == '-')
			f = -1;
			
		c = getchar();
	}
	
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	
	return x * f;
}

inline void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9)
		write(x / 10);
		
	putchar(x % 10 + '0');
}

int n, m, k;
int dis[N][M];
bool f[N][M];
vector<pair<int, int> > E[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

void dijkstra(int s) {
	dis[s][0] = 0;
	q.push({0, s});
	
	while(!q.empty()) {
		auto [p, u] = q.top();
		q.pop();
		
		if(f[u][p % k]) continue;
		
		f[u][p % k] = true;
		
		for(auto [v, w] : E[u]) {
			int t = (p + 1) % k;
			
			if(p >= w) t = p;
			else t = ((w - p + k - 1) / k) * k + p;
				
			if(dis[v][(t + 1) % k] > t + 1) {
				dis[v][(t + 1) % k] = t + 1;
				q.push({t + 1, v});
			}
		}
	}
}

signed main() {
	memset(dis, 0x3f, sizeof dis);
	n = read(), m = read(), k = read();
	
	for(int i = 0; i < m; i++) {
		int u = read(), v = read(), w = read();
		E[u].push_back({v, w});
	}
	
	dijkstra(1);
	
	if(!f[n][0]) puts("-1");
	else write(dis[n][0]);
		
	return 0;
}
