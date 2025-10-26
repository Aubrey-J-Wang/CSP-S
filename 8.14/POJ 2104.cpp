#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+7;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

struct node {
	int l, r, sum;
} T[maxn * 25];

int cnt, root[maxn], a[maxn];
vector<int> v;

int getid(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int l, int r, int& x, int y, int pos) {
	T[++cnt] = T[y], T[cnt].sum++, x = cnt;
	
	if(l == r) return;
	
	int mid = (l + r) >> 1;
	
	if(mid >= pos) update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
	if(l == r) return l;
	
	int mid = (l + r) >> 1, sum = T[T[y].l].sum - T[T[x].l].sum;
	
	if(sum >= k) return query(l, mid, T[x].l, T[y].l, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}

int main(void) {
	int n = read(), m = read();
	
	for(int i = 1; i <= n; i++) a[i] = read(), v.push_back(a[i]);
		
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int i = 1; i <= n; i++)
		update(1, n, root[i], root[i - 1], getid(a[i]));
		
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), k = read();
		write(v[query(1, n, root[x - 1], root[y], k) -1]);
		putchar('\n');
	}
	return 0;
}
