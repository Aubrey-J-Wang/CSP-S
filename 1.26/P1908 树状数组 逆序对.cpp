#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;

int n;
ll c[500001], b[500001];
pair<ll, ll> a[500001];

inline int lowbit(int x) {
	return x & -x;
}

inline void add(int x) {
	while (x <= n) {
		++c[x];
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
	ios::sync_with_stdio(false);
	
	cin >> n;
	int i;
	ll s = 0;
	for (i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort(a + 1, a + n + 1);

	for (i = 1; i <= n; ++i) b[a[i].second] = i;
	
	for (i = n; i; --i) s += sum(b[i]), add(b[i]);
	cout << s;
	
	return 0;
}