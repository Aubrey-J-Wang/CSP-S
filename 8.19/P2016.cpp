#include <iostream>
#include <vector>
using namespace std;

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

const int MAXN = 6005;
int a[MAXN], f[MAXN][2];
vector<int> gv[MAXN];

void dfs(int u, int fa) {
	f[u][0] = 0;
	f[u][1] = 1;
	
	for(auto v : gv[u]) {
		if(v != fa) {
			dfs(v, u);
			f[u][0] += f[v][1];
			f[u][1] += min(f[v][1], f[v][0]);
		}
	}
}

int main() {
	int n = read();
	
	while(n--) {
		int x = read(), y = read();
		
		for(int i = 1; i <= y; i++) {
			int t = read();
			gv[x].push_back(t);
			gv[t].push_back(x);
		}
	}
	
	dfs(0, -1);
	write(min(f[0][0], f[0][1]));
	return 0;
}
