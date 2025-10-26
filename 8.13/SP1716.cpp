#include <iostream>
#include <vector>
using namespace std;

struct node {
	int Left, Right;
	int left_child, right_child;
	int Max, lmax, rmax;
	int sum;
};

vector<node> tree(100010);

int n, total;
int a[50001];
int mid[100010];
int lc[100010], rc[100010];
int sum[100010];

int max(int a, int b, int c) {
	return max(max(a, b), c);
}

void update(int n, int l, int r, int id, int x) {
	auto& v = tree[n];
	if (l == r) {
		v.sum = x;
		v.lmax = x;
		v.rmax = x;
		v.Max = x;
		return;
	}
	
	int mid = (l + r) >> 1;
	if (id <= mid)
		update(n << 1, l, mid, id, x);
	else
		update(n << 1 | 1, mid + 1, r, id, x);
	
	auto lc = tree[n << 1], rc = tree[n << 1 | 1];
	v.sum = lc.sum + rc.sum;
	v.lmax = max(lc.lmax, lc.sum + rc.lmax);
	v.rmax = max(rc.rmax, rc.sum + lc.rmax);
	v.Max = max(lc.Max, max(rc.Max, lc.rmax + rc.lmax));
}

int findmax(int n, int leftn, int rightn) {
	auto& v = tree[n];
	int xl, xr;
	
	if(leftn == v.Left && rightn == v.Right) return v.Max;
	
	if(rightn <= mid[n]) return findmax(v.left_child, leftn, rightn);
	
	if(leftn > mid[n])
		return findmax(v.right_child, leftn, rightn);
		
	xl = findmax(v.left_child, leftn, mid[n]);
	xr = findmax(v.right_child, mid[n] + 1, rightn);
	return max(xl, xr, xl + xr);
}

void build(int l, int r) {
	total++;
	auto& v = tree[total];
	v.Left = l, v.Right = r;
	mid[total] = (l + r) / 2;
	
	if(l == r) {
		v = node(l, r, 0, 0, a[l], a[l], a[l], a[l]);
		return;
	}
	
	v.left_child = total + 1;
	build(l, mid[total]);
	v.right_child = total + 1;
	build(mid[total] + 1, r);
	auto lc = tree[v.left_child], rc = tree[v.right_child];
	v.Max = max(lc.Max, rc.Max, lc.rmax + rc.lmax);
	v.lmax = max(rc.lmax + lc.sum, lc.lmax);
	v.rmax = max(lc.rmax + rc.sum, rc.rmax);
	v.sum = lc.sum + rc.sum;
}

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, n);
	int q;
	cin >> q;
	
	while(q--) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if(opt){
			cout << findmax(1, x, y) << endl;
		}else{
			update(1, 1, n, x, y);
		}
	}
	
	return 0;
}

