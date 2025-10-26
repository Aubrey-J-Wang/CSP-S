#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9') {
		if(c == '-') f = -f;
		
		c = getchar();
	}
	
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}

const int N = 100050;
int d[N], vis[N], s = 1;
vector<pair<int, int> > gv[N];

priority_queue <pair<int, int> > q;

void dijkstra() {
	memset(d, 63, sizeof(d));
	q.push({s, 0});
	d[s] = 0;
	
	while(!q.empty()) {
		int k = q.top().first;
		q.pop();
		
		if(vis[k]) continue;
		
		vis[k] = 1;
		
		for(auto [u, v] : gv[k])
			if(d[u] > max(d[k], v)) {
				d[u] = max(d[k], v);
				
				if(!vis[u]) q.push({u, d[u]});
			}
	}
}

int main() {
	int n = read(), m = read(), K = read();
	int t = n;
	
	for(int i = 1; i <= m; i++) {
		int l = read(), r = read(), q = read();
		gv[l].push_back({r, q});
		gv[q].push_back({l, q});
		
		for(int j = 1; j <= K; j++) {
			gv[j * n + l].push_back({j * n + r, q});
			gv[j * n + r].push_back({j * n + l, q});
			gv[(j - 1)*n + l].push_back({j * n + r, 0});
			gv[(j - 1)*n + r].push_back({j * n + l, 0});
		}
	}
	
	dijkstra();
	write(d[K * n + t] != 1061109567 ? d[K * n + t] : -1);
	return 0;
}

