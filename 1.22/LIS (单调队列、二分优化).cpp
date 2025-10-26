#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int a[200010];

//int f[200010]={-0xf3f3f3f3};
int f[200010] = {1000000};

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a, a+n);
	
	for (int i = 1; i <= n; i++) {
		int tmp = lower_bound(f + 1, f + ans + 1, a[i]) - f;
		
		f[tmp] = a[i];
		if (ans < tmp) ans = tmp;
	}

	cout << ans;  //ans
	return 0;
}