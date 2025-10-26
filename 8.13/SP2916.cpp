#include <bits/stdc++.h>
using namespace std;

int test, n;
int a[10001];
int sum[50001], Max[50001], lmax[50001], rmax[50001];

struct answers {
	int sum, max, lmax, rmax;
};

answers findmax(int node, int left, int right, int x, int y) {
	int mid, lc, rc;
	answers v, vl, vr;
	
	if(x == y + 1) {
		v.sum = 0;
		return v;
	}
	
	if(x == y + 2) {
		v.sum = -a[x - 1];
		return v;
	}
	
	if(left == x && right == y) {
		v.sum = sum[node];
		v.max = Max[node];
		v.lmax = lmax[node];
		v.rmax = rmax[node];
		return v;
	}
	
	mid = (left + right) / 2;
	lc = node * 2;
	rc = node * 2 + 1;
	
	if(y <= mid) return findmax(lc, left, mid, x, y);
	
	if(x > mid) return findmax(rc, mid + 1, right, x, y);
	
	vl = findmax(lc, left, mid, x, mid);
	vr = findmax(rc, mid + 1, right, mid + 1, y);
	v.sum = vl.sum + vr.sum;
	v.max = max(vl.max, max(vr.max, vl.rmax + vr.lmax));
	v.lmax = max(vl.lmax, vl.sum + vr.lmax);
	v.rmax = max(vr.rmax, vr.sum + vl.rmax);
	return v;
}

int findsum(int node, int left, int right, int x, int y) {
	int mid, lc, rc;
	
	if(left == x && right == y) return sum[node];
	
	mid = (left + right) / 2;
	lc = node * 2;
	rc = node * 2 + 1;
	
	if(y <= mid) return findsum(lc, left, mid, x, y);
	
	if(x > mid) return findsum(rc, mid + 1, right, x, y);
	
	return findsum(lc, left, mid, x, mid) + findsum(rc, mid + 1, right, mid + 1, y);
}

void build(int node, int left, int right) {
	int lc, rc, mid;
	
	if(left == right) {
		sum[node] = a[left];
		Max[node] = a[left];
		lmax[node] = a[left];
		rmax[node] = a[left];
		return;
	}
	
	lc = node * 2;
	rc = node * 2 + 1;
	mid = (left + right) / 2;
	build(lc, left, mid);
	build(rc, mid + 1, right);
	sum[node] = sum[lc] + sum[rc];
	Max[node] = max(Max[lc], max(Max[rc], rmax[lc] + lmax[rc]));
	lmax[node] = max(lmax[lc], sum[lc] + lmax[rc]);
	rmax[node] = max(rmax[rc], sum[rc] + rmax[lc]);
}

void Main() {
	int q;
	int x1, y1, x2, y2;
	int ans_1, ans_2, ans_3, ans_4;
	int ans_2_1, ans_2_2, ans_2_3, ans;
	cin >> q;
	
	while(q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		
		if(y1 <= x2) {
			ans_1 = findmax(1, 1, n, x1, y1).rmax;
			ans_2 = findmax(1, 1, n, y1 + 1, x2 - 1).sum;
			ans_3 = findmax(1, 1, n, x2, y2).lmax;
			ans = ans_1 + ans_2 + ans_3;
		} else {
			ans_1 = findmax(1, 1, n, x1, x2).rmax + findmax(1, 1, n, x2, y1).lmax - a[x2];
			ans_2_1 = findmax(1, 1, n, x1, x2).rmax;
			ans_2_2 = findmax(1, 1, n, x2 + 1, y1 - 1).sum;
			ans_2_3 = findmax(1, 1, n, y1, y2).lmax;
			ans_2 = ans_2_1 + ans_2_2 + ans_2_3;
			ans_3 = findmax(1, 1, n, x2, y1).rmax + findmax(1, 1, n, y1, y2).lmax - a[y1];
			ans = max(ans_1, max(ans_2, ans_3));
			
			if(x2 + 1 <= y1 - 1) {
				ans_4 = findmax(1, 1, n, x2 + 1, y1 - 1).max;
				ans = max(ans, ans_4);
			}
		}
		
		cout << ans << endl;
	}
}

int main() {
	cin >> test;
	
	while(test--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		build(1, 1, n);
		Main();
	}
	
	return 0;
}
