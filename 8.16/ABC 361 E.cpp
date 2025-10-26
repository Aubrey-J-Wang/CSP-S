#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int read();
void write(int x);

vector<pair<int, int> > gv[100005];
int mx, sum, dist[100005];

int dfs(int vertex, int from){
	for(auto [u, w] : gv[vertex]){
		if(u == from) continue;
		dist[u] = dist[vertex] + w;
		dfs(u, vertex);
		mx = max(mx, dist[u]);
	}
}

int main(){
	int n = read();
	
	for(int i = 1; i < n; i++){
		int u = read(), v = read(), w = read();
		sum += w*2;
		gv[u].push_back({v, w});
		gv[v].push_back({u, w});
	}
	
	dfs(1, 0);
	int node = max_element(dist+1, dist+n+1) - dist;
	memset(dist, 0, sizeof(dist[0]) * (n + 3));
	mx = 0;
	dfs(node, 0);
	
	write(sum-mx);
	return 0;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
