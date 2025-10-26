#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll c[500001], b[500001];
pair<ll, ll> a[500001];

inline int lowbit(int x) {
	return x& -x;
}

inline void add(int x) {
	while (x <= n) {
		++c[x]; //±¾À´£º c[x] += y;
		x += lowbit(x);
	}
	return;
}

inline int sum(int x) { //x=6
	int s = 0;
	while (x) {
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int i;
	ll s = 0;
	for (i = 1; i <= n; ++i) { //3000 10 400000000 200
		cin >> a[i].first; //1 2 3 4
		a[i].second = i;
	}
	sort(a + 1, a + n + 1); //10 200 3000 400000000
//2 4 1 3
	for (i = 1; i <= n; ++i)
		b[a[i].second] = i; //b=[0,3,1,4,2]
	for (i = n; i; --i) //3, 1, 4, 2
		s += sum(b[i]), add(b[i]);
	cout << s;
}