#include <bits/stdc++.h>
#define l(x) tree[x].l
#define r(x) tree[x].r
#define add(x) tree[x].add
#define sum(x) tree[x].sum
#define int long long
using namespace std;

const int N = 100010;
const int M = 2 * N;

struct SegmentTree {
	int l, r, add, sum;
} tree[8 * N];

int n, m, a[N];
int in[N], out[N], vis[M];
int head[N], ver[M], nxt[M];
int c[M], num[M];
int dfn, tot;

void addedge(int x, int y) {
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	in[x] = ++dfn;
	num[dfn] = x;
	vis[dfn] = 1;
	
	for(int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		
		if(y != fa)
			dfs(y, x);
	}
	
	out[x] = ++dfn;
	num[dfn] = x;
	vis[dfn] = -1;
}

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	
	if(l == r) {
		sum(p) = vis[l] * a[num[l]];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	sum(p) = sum(p * 2) + sum(p * 2 + 1);
}

void spread(int p) {
	int add = add(p);
	sum(p * 2) += add * (c[r(p * 2)] - c[l(p * 2) -1]);
	sum(p * 2 + 1) += add * (c[r(p * 2 + 1)] - c[l(p * 2 + 1) -1]);
	add(p * 2) += add;
	add(p * 2 + 1) += add;
	add(p) = 0;
}

void change(int p, int id, int d) {
	int l = l(p), r = r(p);
	
	if(l == id && r == id) {
		sum(p) += d;
		return;
	}
	
	spread(p);
	int mid = (l + r) >> 1;
	
	if(mid >= id) change(p * 2, id, d);
	else change(p * 2 + 1, id, d);
	
	sum(p) = sum(p * 2) + sum(p * 2 + 1);
	return;
}

void update(int p, int l, int r, int d) {
	int L = l(p), R = r(p);
	
	if(l <= L && R <= r) {
		sum(p) += (c[R] - c[L - 1]) * d;
		add(p) += d;
		return;
	}
	
	if(add(p)) spread(p);
	
	int mid = (L + R) >> 1;
	
	if(l <= mid) update(p * 2, l, r, d);
	
	if(r > mid) update(p * 2 + 1, l, r, d);
	
	sum(p) = sum(p * 2) + sum(p * 2 + 1);
}

int query(int p, int l, int r) {
	int val = 0;
	
	if(l <= l(p) && r >= r(p))
		return sum(p);
		
	if(add(p)) spread(p);
	
	int mid = (l(p) + r(p)) >> 1;
	
	if(l <= mid) val += query(p * 2, l, r);
	
	if(r > mid) val += query(p * 2 + 1, l, r);
	
	return val;
}

signed main() {
	scanf("%lld%lld", &n, &m);
	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
		
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
	
	dfs(1, 0);
	
	for(int i = 1; i <= dfn; i++)
		c[i] = c[i - 1] + vis[i];
		
	build(1, 1, 2 * n);
	
	for(int i = 1; i <= m; i++) {
		int op, x, d;
		scanf("%lld", &op);
		
		if(op == 1) {
			scanf("%lld%lld", &x, &d);
			change(1, in[x], d);
			change(1, out[x], -d);
		} else if(op == 2) {
			scanf("%lld%lld", &x, &d);
			update(1, in[x], out[x], d);
		} else {
			scanf("%lld", &x);
			printf("%lld\n", query(1, 1, in[x]));
		}
	}
	
	return 0;
}

