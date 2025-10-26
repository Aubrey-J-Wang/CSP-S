#include <iostream>
using namespace std;
typedef long long ll;
ll n, m1, m2, m, i, s, t;
ll a[501][3];
ll j, f, x, xx, maxv = 0ll, minv = 1e8, q = 0ll;
int main() {
	cin >> n;
	cin >> m1 >> m2;
	if (m1 == 1){
		cout << 0;
		return 0;
	}
	ll b[n + 1];
	m = m1, i = 1;
	do{
		i++;
		if (m % i == 0){
			s++;
			a[s][1] = i;
			a[s][2] = 0;
			while (m % i == 0){
				a[s][2] += m2;
				m /= i;
			}
		}
	}while (m != 1);
	for (i = 1; i <= n; i++) cin >> b[i];
	for (i = 1; i <= n; i++){
		m = b[i];
		f = 1;
		maxv = 0;
		for (j = 1; j <= s; j++){
			t = 0;
			x = a[j][1];
			if (m % x != 0){
				f = 0;
				break;
			}
			while (m % x == 0){
				t++;
				m /= x;
			}
			if (a[j][2] % t == 0) xx = a[j][2] / t;
			else xx = a[j][2] / t + 1;
			if (xx > maxv) maxv = xx;
		}
		if (minv > maxv || minv == 1e8) minv = maxv;
		q += f;
	}
	if (q == 0)	cout << -1;
	else cout << minv;
	return 0;
}

