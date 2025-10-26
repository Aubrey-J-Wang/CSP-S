#include <cstdio>
const int MAX_N = 1000005;
int v[MAX_N], ch[MAX_N][2], c[MAX_N];
int ans;

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

bool same(int a, int b) {
	if(a == b) return 1;
	if(!a || !b) return 0;

	return v[a] == v[b] && same(ch[a][0], ch[b][1]) && same(ch[a][1], ch[b][0]);
}

void dfs(int i) {
	if(!i) return;
	
	dfs(ch[i][0]);
	dfs(ch[i][1]);
	
	c[i] = 1 + c[ch[i][0]] + c[ch[i][1]];
	v[i] = v[i] + v[ch[i][0]] + v[ch[i][1]];
	
	if(ans < c[i] && same(ch[i][0], ch[i][1])) ans = c[i];
}

int main() {
	int n = read();
	for(int i = 1; i <= n; ++i)
		v[i] = read();
	
	v[0] = 1005;
	for(int i = 1; i <= n; ++i)
		for(int& k : ch[i]) {
			k = read();
			if(k == -1) k = 0;
		}
	
	dfs(1);
	
	write(ans);
	return 0;
}
