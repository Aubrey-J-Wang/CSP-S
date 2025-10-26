#include <iostream>
#include <algorithm>
#define l(p) t[p].l
#define r(p) t[p].r
#define cnt(p) t[p].cnt
#define sum(p) t[p].sum
#define mid ((l(p)+r(p))/2)
#define left_child(p) (p)<<1
#define right_child(p) (p)<<1|1
#define int long long
using namespace std;

const int N = 50010;
const int M = 200010;
int n, m, ans, tot;

struct node {
	int v, x;
	bool operator < (const node& a){
		return v < a.v;
	}
} cow[N];

struct segment_tree {
	int l, r, cnt, sum;
} t[M];

void push_up(int p) {
	cnt(p) = cnt(left_child(p)) + cnt(right_child(p));
	sum(p) = sum(left_child(p)) + sum(right_child(p));
}

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	
	if(l == r) return;
	
	build(left_child(p), l, mid);
	build(right_child(p), mid + 1, r);
}

void change(int p, int x, int d) {
	if(l(p) == r(p)) {
		cnt(p)++;
		sum(p) += d;
		return;
	}
	
	if(x <= mid) change(left_child(p), x, d);
	else change(right_child(p), x, d);
	
	push_up(p);
}

int ask_cnt(int p, int l, int r) {
	if(l <= l(p) && r >= r(p)) return cnt(p);
	
	int val = 0;
	
	if(l <= mid) val += ask_cnt(left_child(p), l, r);
	if(r > mid) val += ask_cnt(right_child(p), l, r);
	return val;
}

int ask_sum(int p, int l, int r) {
	if(l <= l(p) && r >= r(p)) return sum(p);
	
	int val = 0;
	
	if(l <= mid) val += ask_sum(left_child(p), l, r);
	if(r > mid) val += ask_sum(right_child(p), l, r);
	return val;
}

signed main() {
	ios::sync_with_stdio(false);
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> cow[i].v >> cow[i].x;
		m = max(m, cow[i].x);
	}
	
	sort(cow + 1, cow + n + 1);
	build(1, 1, m);
	
	for(int i = 1; i <= n; i++) {
		int c = ask_cnt(1, 1, cow[i].x), s = ask_sum(1, 1, cow[i].x);
		ans += (c * cow[i].x - s) * cow[i].v + ((tot - s) - (i - c - 1) * cow[i].x) * cow[i].v;
		
		change(1, cow[i].x, cow[i].x);
		tot += cow[i].x;
	}
	
	cout << ans;
	return 0;
}
