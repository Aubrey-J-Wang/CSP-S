#include <bits/stdc++.h>
using namespace std;
int n, m, c[500005];

int lowbit(int x) {
	return x&(-x);
}

int sum(int x) { //x=6
	int s = 0;
	while (x > 0) {
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}

void change(int x, int y) { //a[1] += y; x=1
	while (x <= n) {
		c[x] += y;
		x += lowbit(x);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t1;
		cin >> t1;
		change(i, t1);
	}
	for (int i = 1; i <= m; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 1)
			change(t2, t3);
		if (t1 == 2)
			cout << sum(t3) - sum(t2 - 1) << endl;
	}
	return 0;
}