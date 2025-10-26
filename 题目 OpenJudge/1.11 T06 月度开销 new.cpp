#include<iostream>
using namespace std;

int i, j, mid, ans, n, m, a[100005], sum = 0, minv = 10005, maxv = 0, L, R;

bool check(int nn) {
	int s = 0, cnt = 0;

	for(int k = 1; k <= n; k++) {
		if(a[k] + s <= nn) {
			s += a[k];
		}
		else {
			cnt++;
			s = a[k];
		}
	}

	if(cnt + 1 > m) return false;
	else return true;
}

int main() {
	cin >> n >> m;

	for(i = 1; i <= n; i++) {
		cin >> a[i];

		sum += a[i];
		if(a[i] > maxv) maxv = a[i]; //500
	}

	L = maxv;
	R = sum;

	while(L <= R) {
		mid = (L + R) / 2;

		if(check(mid)) { //If parts <= m, go 'left'.
			ans = mid;
			R = mid - 1;
		}
		else {           //If parts > m, go 'right'.
			L = mid + 1;
		}
	}

	cout << ans << endl;
	return 0;
}
