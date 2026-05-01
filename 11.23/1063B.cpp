#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 2048, MOD = 1000000007;
int n, m, sx, sy, l0, r0;

struct Node {
	Node(int _x, int _y, int _l, int _r): x(_x), y(_y), l(_l), r(_r) {}
	int x, y, l, r;
};

deque<Node> dq;
char mp[M][M], vis[M][M];

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	
	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;
		
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x * f;
}

inline void go(int x, int y, int l, int r, int t) {
	if(mp[x][y] == '.' && vis[x][y] == 0 && l <= l0 && r <= r0) {
		vis[x][y] = 1;
		
		if(t) dq.emplace_back(x, y, l, r);
		else dq.emplace_front(x, y, l, r);
	}
}

int main(void) {
	n = read(), m = read(), sx = read(), sy = read(), l0 = read(), r0 = read();
	
	for(int i = 1; i <= n; ++i)
		scanf("%s", mp[i] + 1);
		
	vis[sx][sy] = 1;
	dq.emplace_front(sx, sy, 0, 0);
	int ans = 0;
	
	for(Node p = dq.front(); !dq.empty(); ++ans) {
		p = dq.front(); dq.pop_front();
		go(p.x + 1, p.y, p.l, p.r, 0);
		go(p.x - 1, p.y, p.l, p.r, 0);
		go(p.x, p.y + 1, p.l, p.r + 1, 1);
		go(p.x, p.y - 1, p.l + 1, p.r, 1);
	}
	
	printf("%d", ans);
	return 0;
}
