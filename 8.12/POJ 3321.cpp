#include <vector>
#include <iostream>
#include <cstdio>
#define int long long
#define left_child(k) ((k) << 1)
#define right_child(k) ((k) << 1 | 1)
using namespace std;
const int N = 100005;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int in[N], out[N];
int Left[N << 2], Right[N << 2], sum[N << 2];

vector<int> gv[N];
vector<int> q;

void dfs(int x, int from) {
	q.push_back(x);
	in[x] = q.size();
	
	for(int& i : gv[x])
		if(i != from) dfs(i, x);
			
	out[x] = q.size();
}

void build(int k, int l, int r) {
	int mid = (l + r) >> 1;
	Left[k] = l, Right[k] = r;
	
	if(l == r) {
		sum[k] = 1;
		return;
	}
	
	build(left_child(k), l, mid);
	build(right_child(k), mid + 1, r);
	sum[k] = sum[left_child(k)] + sum[right_child(k)];
}

int query(int k, int a, int b) {
	int l = Left[k], r = Right[k];
	int mid = (l + r) >> 1;
	
	if(l == a && r == b) return sum[k];
		
	if(b <= mid) return query(left_child(k), a, b);
	else if(a > mid) return query(right_child(k), a, b);
	else return query(left_child(k), a, mid) + query(right_child(k), mid + 1, b);
}

void modify(int k, int x) {
	int l = Left[k], r = Right[k];
	int mid = (l + r) >> 1;
	
	if(l == r) {
		sum[k] ^= 1;
		return;
	}
	
	if(x <= mid) modify(left_child(k), x);
	else modify(right_child(k), x);
		
	sum[k] = sum[left_child(k)] + sum[right_child(k)];
}

signed main() {
	int n = read();
	
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		gv[u].push_back(v);
		gv[v].push_back(u);
	}
	
	dfs(1, 0);
	build(1, 1, n);
	
	int m = read();
	while(m--) {
		string str;
		cin >> str;
		int x = read();
		
		if(str[0] == 'Q') printf("%lld\n", query(1, in[x], out[x]));
		else modify(1, in[x]);
	}
	
	return 0;
}

