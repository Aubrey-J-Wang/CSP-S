#include <bits/stdc++.h>
#define int long long
using namespace std;

int in() {
	int x = 0, f = 1;
	char c = getchar();

	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
		c = getchar();
	}

	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}

	return x * f;
}

int n, d;

struct node {
	int x, y;
} a[1000005];

bool cmp(node x, node y) {
	return x.x < y.x;
}

deque<int> q;
bool f1[100005], f2[100005];

signed main() {
	cin >> n >> d;

	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;

	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++) {
		while (!q.empty() && a[q.back()].y < a[i].y)
			q.pop_back();
		while (!q.empty() && a[i].x - a[q.front()].x > d)
			q.pop_front();

		q.push_back(i);

		if (a[q.front()].y >= a[i].y * 2)
			f1[i] = true;
	}

	q.clear();

	for (int i = n; i ; i--) {
		while (!q.empty() && a[q.back()].y < a[i].y)
			q.pop_back();
		while (!q.empty() && a[q.front()].x - a[i].x > d)
			q.pop_front();
		q.push_back(i);
		if (a[q.front()].y >= a[i].y * 2)
			f2[i] = true;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (f1[i] && f2[i])
			ans++;

	cout << ans << endl;
	return 0;
}

