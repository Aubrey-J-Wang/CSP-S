#include<cstdio>
#include<iostream>
#define N 100005
#define inf 0x7fffffff
#define ll long long
using namespace std;

ll read() {
	ll x = 0, f = 1; char ch = getchar();
	
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

int n, m, id, cnt;
int q[N], st[N], ed[N], last[N];
int rl[N << 2], rr[N << 2], sum[N << 2];

struct data {
	int to, next;
} e[N << 1];

void insert(int u, int v) {
	e[++cnt].to = v; e[cnt].next = last[u]; last[u] = cnt;
	e[++cnt].to = u; e[cnt].next = last[v]; last[v] = cnt;
}

void dfs(int x, int fa) {
	q[++id] = x;
	st[x] = id;
	
	for(int i = last[x]; i; i = e[i].next)
		if(e[i].to != fa)
			dfs(e[i].to, x);
			
	ed[x] = id;
}

void build(int k, int l, int r) {
	int mid = (l + r) >> 1;
	rl[k] = l; rr[k] = r;
	
	if(l == r) {
		sum[k] = 1;
		return;
	}
	
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

int query(int k, int a, int b) {
	int l = rl[k], r = rr[k], mid = (l + r) >> 1;
	
	if(l == a && r == b)
		return sum[k];
		
	if(b <= mid)
		return query(k << 1, a, b);
	else if(a > mid)
		return query(k << 1 | 1, a, b);
	else
		return query(k << 1, a, mid) + query(k << 1 | 1, mid + 1, b);
}

void modify(int k, int x) {
	int l = rl[k], r = rr[k], mid = (l + r) >> 1;
	
	if(l == r) {
		sum[k] ^= 1;
		return;
	}
	
	if(x <= mid)
		modify(k << 1, x);
	else
		modify(k << 1 | 1, x);
		
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

int main() {
	n = read();
	
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		insert(u, v);
	}
	
	dfs(1, 0);
	m = read();
	char ch[10];
	build(1, 1, n);
	
	for(int i = 1; i <= m; i++) {
		scanf("%s", ch + 1);
		int x = read();
		
		if(ch[1] == 'Q')
			printf("%d\n", query(1, st[x], ed[x]));
		else
			modify(1, st[x]);
	}
	
	return 0;
}

