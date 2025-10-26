#include<iostream>
#include<algorithm>
#define int long long
#define left_child(p) ((p) << 1)
#define right_child(p) ((p) << 1 | 1)
using namespace std;

const int MAXN = 2e4+5;
int k, n, c;

struct node1 {
	int l, r, maxn;
	bool operator < (node1 y){
		return r < y.r;
	}
} a[MAXN];

struct abigtree {
	struct node {
		int l, r, lazy, maxn;
	} tree[MAXN << 2];
	
	void push_down(int p) {
		if(tree[p].lazy != 0) {
			tree[left_child(p)].lazy += tree[p].lazy;
			tree[left_child(p)].maxn += tree[p].lazy;
			tree[right_child(p)].lazy += tree[p].lazy;
			tree[right_child(p)].maxn += tree[p].lazy;
			tree[p].lazy = 0;
		}
	}
	
	void build(int l, int r, int p) {
		tree[p].l = l, tree[p].r = r;
		tree[p].lazy = tree[p].maxn = 0;
		
		if(l == r) return;
			
		int mid = l + r >> 1;
		build(l, mid, left_child(p));
		build(mid + 1, r, right_child(p));
	}
	
	void change(int l, int r, int x, int p) {
		if(l <= tree[p].l && tree[p].r <= r) {
			tree[p].lazy += x;
			tree[p].maxn += x;
			return ;
		}
		
		int mid = tree[p].l + tree[p].r >> 1;
		push_down(p);
		
		if(l <= mid)
			change(l, r, x, p << 1);
			
		if(r > mid)
			change(l, r, x, p << 1 | 1);
			
		tree[p].maxn = max(tree[p << 1].maxn, tree[p << 1 | 1].maxn);
	}
	
	int query(int l, int r, int p) {
		if(l <= tree[p].l && tree[p].r <= r)
			return tree[p].maxn;
			
		int mid = tree[p].l + tree[p].r >> 1;
		push_down(p);
		
		if(l <= mid)
			return max(0ll, query(l, r, p << 1));
			
		if(r > mid)
			return max(0ll, query(l, r, p << 1 | 1));
			
		return 0;
	}
} line_tree;

signed main() {
	cin >> k >> n >> c;
	
	for(int i = 1; i <= k; i++)
		cin >> a[i].l >> a[i].r >> a[i].maxn;
		
	sort(a + 1, a + k + 1);
	line_tree.build(1, n, 1);
	
	int ans = 0;
	for(int i = 1; i <= k; i++) {
		int still = min(a[i].maxn, c - line_tree.query(a[i].l, a[i].r - 1, 1));
		ans += still;
		line_tree.change(a[i].l, a[i].r - 1, still, 1);
	}
	cout << ans;
	return 0;
}

