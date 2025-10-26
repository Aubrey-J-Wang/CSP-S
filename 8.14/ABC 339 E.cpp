#include <iostream>
using namespace std;

const int SIZE = 5 * 1e5;
int n, d, a[SIZE + 1];

struct segment_tree {
	int l, r, dat;
} t[SIZE << 2 | 1];

void build(int pt, int l, int r) {
	t[pt] = segment_tree(l, r, 0);
	
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	build(pt << 1, l, mid);
	build(pt << 1 | 1, mid + 1, r);
	t[pt].dat = max(t[pt << 1].dat, t[pt << 1 | 1].dat);
}

void change(int p, int x, int v) {
	if(t[p].l == t[p].r) {
		t[p].dat = max(t[p].dat, v);
		return;
	}
	
	int mid = t[p].l + t[p].r >> 1;
	
	if(x <= mid) change(p << 1, x, v);
	else change(p << 1 | 1, x, v);
	
	t[p].dat = max(t[p << 1].dat, t[p << 1 + 1].dat);
}

int ask(int p, int l, int r) {
	if(l <= t[p].l && t[p].r <= r)
		return t[p].dat;
		
	int mid = t[p].l + t[p].r >> 1;
	int val = -0x3f3f3f3f;
	
	if(l <= mid) val = max(val, ask((p << 1), l, r));
	
	if(r > mid) val = max(val, ask((p << 1) + 1, l, r));
	
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> d;
	int mn = 1e9, mx = 0;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	
	build(1, mn, mx);
	int ans = 0;
	
	for(int i = 1; i <= n; i++) {
		int f = 1, l = max(mn, a[i] - d), \
		               r = min(mx, a[i] + d);
		f = max(f, ask(1, l, r) + 1);
		ans = max(ans, f);
		change(1, a[i], f);
	}
	
	cout << ans << endl;
	return 0;
}
