#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

const int maxn = 1e5+10;

struct Node {
	int l, r, ls, rs, sum, lazy;
} node[2 * maxn];

namespace wjz{
	int size[maxn];
}

int rt, n, m, cnt, head[maxn];
int f[maxn], d[maxn], son[maxn], rk[maxn], top[maxn], tid[maxn];
vector<int> gv[maxn];

int readn() {
	int x = 0;
	char ch = getchar();
	
	while(ch < '0' || ch > '9')
		ch = getchar();
		
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	
	return x;
}

void dfs1(int u, int fa, int depth) {
	using wjz::size;
	f[u] = fa, d[u] = depth, size[u] = 1;
	
	for(int v : gv[u]) {
		if(v == fa) continue;
		
		dfs1(v, u, depth + 1);
		size[u] += size[v];
		
		if(size[v] > size[son[u]] || !son[u]) son[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	tid[u] = ++cnt;
	rk[cnt] = u;
	
	if(!son[u]) return;
	
	dfs2(son[u], t);
	
	for(int v : gv[u]) {
		if(v != son[u] && v != f[u]) dfs2(v, v);
	}
}

void pushup(int x) {
	int lson = node[x].ls, rson = node[x].rs;
	node[x].sum = node[lson].sum + node[rson].sum;
	node[x].l = node[lson].l;
	node[x].r = node[rson].r;
}

void build(int li, int ri, int cur) {
	if(li == ri) {
		node[cur].ls = node[cur].rs = node[cur].lazy = -1;
		node[cur].l = node[cur].r = li;
		return;
	}
	
	int mid = (li + ri) >> 1;
	node[cur].ls = cnt++;
	node[cur].rs = cnt++;
	build(li, mid, node[cur].ls);
	build(mid + 1, ri, node[cur].rs);
	pushup(cur);
}

void pushdown(int x) {
	int lson = node[x].ls, rson = node[x].rs;
	node[lson].sum = node[x].lazy * (node[lson].r - node[lson].l + 1);
	node[rson].sum = node[x].lazy * (node[rson].r - node[rson].l + 1);
	node[lson].lazy = node[x].lazy;
	node[rson].lazy = node[x].lazy;
	node[x].lazy = -1;
}

void update(int li, int ri, int c, int cur) {
	if(li <= node[cur].l && node[cur].r <= ri) {
		node[cur].sum = c * (node[cur].r - node[cur].l + 1);
		node[cur].lazy = c;
		return;
	}
	
	if(node[cur].lazy != -1) pushdown(cur);
	
	int mid = (node[cur].l + node[cur].r) >> 1;
	
	if(li <= mid)
		update(li, ri, c, node[cur].ls);
		
	if(mid < ri)
		update(li, ri, c, node[cur].rs);
		
	pushup(cur);
}

int query(int li, int ri, int cur) {
	if(li <= node[cur].l && node[cur].r <= ri)
		return node[cur].sum;
		
	if(node[cur].lazy != -1)
		pushdown(cur);
		
	int tot = 0;
	int mid = (node[cur].l + node[cur].r) >> 1;
	
	if(li <= mid)
		tot += query(li, ri, node[cur].ls);
		
	if(mid < ri)
		tot += query(li, ri, node[cur].rs);
		
	return tot;
}

int sum(int x) {
	int ans = 0;
	int fx = top[x];
	
	while(fx) {
		ans += tid[x] - tid[fx] + 1 - query(tid[fx], tid[x], rt);
		update(tid[fx], tid[x], 1, rt);
		x = f[fx];
		fx = top[x];
	}
	
	ans += tid[x] - tid[0] - query(tid[0], tid[x], rt) +1;
	update(tid[0], tid[x], 1, rt);
	return ans;
}

signed main() {
	using wjz::size;
	n = readn();
	
	for(int i = 1; i < n; i++) {
		int x = readn();
		gv[x].push_back(i);
		gv[i].push_back(x);
	}
	
	cnt = 0;
	dfs1(0, -1, 1);
	dfs2(0, 0);
	cnt = 0;
	rt = cnt++;
	build(1, n, rt);
	m = readn();
	
	for(int i = 1; i <= m; i++) {
		int x;
		string op;
		cin >> op;
		x = readn();
		
		if(op == "install")
			printf("%lld\n", sum(x));
		else if(op == "uninstall") {
			printf("%lld\n", query(tid[x], tid[x] + size[x] - 1, rt));
			update(tid[x], tid[x] + size[x] - 1, 0, rt);
		}
	}
	
	return 0;
}
