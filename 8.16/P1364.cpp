#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

const int MAXN = 10010;

vector<int> gv[MAXN];
int w[MAXN];
long long ans = LONG_LONG_MAX, f[MAXN];

namespace wjz{
	int size[MAXN];
}

void dfs(int u, int fa, int dep) {
	using wjz::size;
	size[u] = w[u];
	
	for(int v : gv[u]) {
		if(v == fa) continue;
		dfs(v, u, dep + 1);
		size[u] += size[v];
	}
	
	f[1] += w[u] * dep;
}

void dp(int u, int fa) {
	using wjz::size;
	for(int v : gv[u]){
		if(v == fa) continue;
		f[v] = f[u] + size[1] - size[v] * 2;
		dp(v, u);
	}
	ans = min(ans, f[u]);
}

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) {
		w[i] = read();
		int a = read(), b = read();
		
		if(a){
			gv[i].push_back(a);
			gv[a].push_back(i);
		}
		
		if(b){
			gv[i].push_back(b);
			gv[b].push_back(i);
		}
	}
	
	dfs(1, 0, 0);
	dp(1, 0);
	
	write(ans);
	return 0;
}


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

void write(long long x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}
