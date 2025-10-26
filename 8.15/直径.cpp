#include <iostream>
#include <vector>
#include <cstring>
#define maxn 100000
using namespace std;
int read();
void write(int x);

vector<pair<int, int> > gv[maxn+10];
int d[maxn + 10], f_num, cnt = 0, ans;

inline void dfs(int vertex, int father) {
	if(ans < d[vertex]) {
		ans = d[vertex];
		f_num = vertex;
	}
	
	for(auto& [v, w] : gv[vertex]) {
		if(v == father) continue;
		
		d[v] = d[vertex] + w;
		dfs(v, vertex);
	}
}

int main() {
	int n = read(), m = read(); // N has nothing to do with the process.
	
	while(m--) {
		int x, y, z;
		x = read(); y = read(); z = read();
		gv[x].push_back({y, z});
		gv[y].push_back({x, z});
	}
	
	dfs(1, 0);
	ans = d[f_num] = 0;
	
	dfs(f_num, 0);
	
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

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}
